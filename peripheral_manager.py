from threading import Thread
from pubsub import pub
from datetime import datetime
from webcam import Webcam
import pandas as pd
from time import sleep


class PeripheralManager:
    def __init__(self, timeout=60):
        # camera objects for the webcams
        self.camera1 = Webcam(0)
        self.camera2 = Webcam(2)

        # {antenna_number: webcam}
        self.antenna_cam_pair = {4: self.camera2, 8: self.camera2, 1: self.camera1, 2: self.camera1}

        # timeout for how long a participant has to walk across the hallway before the video is considered finished
        self.walk_timeout = timeout

        # timeout for how many seconds before or after the participant tag an RA tag can be scanned and the walk to
        # considered cued
        self.cue_timeout = 7

        # timeout for how many times in a row a scan can be detected (caused by being near the scanner for too long)
        # for all scans to be considered as one scan
        self.repeated_scan_timeout = 5

        # {tag_number: {startTime: datetime, startAntenna: int, cued: bool, endTime: datetime,
        #               exitAntenna: int, recentScan: datetime}}
        self.active_recordings = {}

        # thread to manage timeouts and the removal of finished recordings from the dictionary
        self.timeout_check_thread = Thread(target=self.threaded_timeout_check, daemon=True)
        self.timeout_check_thread.start()

        # list of RA tags
        self.ra_tags = [0]

        # dictionary to hold the most recent RA tag scan
        self.ra_tag_scan_time = {self.camera1: datetime(1, 1, 1), self.camera2: datetime(1, 1, 1)}

        # dataframe to store variables for each walk and store in a csv
        try:
            self.df_history = pd.read_csv('output.csv')
        except:
            self.df_history = pd.DataFrame({'participantTag': [],
                                            'startTime': [],
                                            'startAntenna': [],
                                            'cued': [],
                                            'endTime': [],
                                            'exitAntenna': [],
                                            'recentScan': []
                                            })

        # subscribe to the TagScan topic to receive information from the RFID receiver
        pub.subscribe(self.rfid_receiver, 'TagScan')

    # time out if the participant doesn't walk across the hallway within the timeout period AND the participant tag
    # hasn't been scanned again for exit --> stop recording
    def threaded_timeout_check(self):
        while True:
            sleep(0.1)
            now = datetime.now()
            temp_active_recordings = self.active_recordings.copy()
            if temp_active_recordings:
                for tag in temp_active_recordings:
                    '''
                    print('')
                    print(now)
                    print('{0} duration: {1}'.format(tag, abs(
                        (now - temp_active_recordings[tag]['startTime']).total_seconds())))
                    print('{0} endTime: {1}'.format(tag, temp_active_recordings[tag]['endTime']))
                    '''
                    if (abs((now - temp_active_recordings[tag]['startTime']).total_seconds()) > self.walk_timeout) \
                        and temp_active_recordings[tag]['endTime'] is None:
                            self.stop_record(None, tag)
                    if temp_active_recordings[tag]['endTime'] is not None:
                        # print('{0} postEnd: {1}'.format(tag, abs(
                            # (now - temp_active_recordings[tag]['endTime']).total_seconds())))

                        # if the participant tag hasn't been scanned again for exit within the timeout period, but scanned repeatedly
                        # likely when patient standing near scanner for too long --> stop recording, save to csv and remove
                        if abs((now - temp_active_recordings[tag][
                            'endTime']).total_seconds()) > self.repeated_scan_timeout:
                            self.df_history = self.df_history.append(self.active_recordings[tag], ignore_index=True)
                            self.df_history.to_csv('output.csv', index=False)
                            self.active_recordings.pop(tag, None)

    def rfid_receiver(self, antenna, patient_id):
        print(f'Received scan from antenna {antenna}, tag {patient_id}')

        # if it's an RA tag, change all the walks recorded by the respective camera to cued walks if the recording
        # has begun within 5s of the RA tag scan
        if patient_id in self.ra_tags:
            print('RA tag scanned')
            cam = self.antenna_cam_pair[antenna]
            self.ra_tag_scan_time[cam] = datetime.now()
            for recording in self.active_recordings:
                if self.antenna_cam_pair[self.active_recordings[recording]['startAntenna']] == cam and \
                        abs((datetime.now() - self.active_recordings[recording]['startTime']).total_seconds()) < self.cue_timeout:
                    print('setting recording to cued')
                    self.active_recordings[recording]['cued'] = True
            return

        # if tag is not in the active recordings, add it and start recording
        if patient_id not in self.active_recordings:
            self.active_recordings[patient_id] = {'participantTag': patient_id, 'startTime': datetime.now(), 'startAntenna': antenna,
                                           'cued': False,
                                           'endTime': None, 'exitAntenna': -1, 'recentScan': datetime.now()}
            cam = self.antenna_cam_pair[antenna]
            if abs((self.ra_tag_scan_time[cam] - self.active_recordings[patient_id][
                'startTime']).total_seconds()) < self.cue_timeout:
                self.active_recordings[patient_id]['cued'] = True
            self.start_record(antenna, patient_id)

        else:
            # if the tag was recently scanned, we assume that the RFID has had a chance to scan it multiple times
            # before the participant can exit its range
            if abs((datetime.now() - self.active_recordings[patient_id]['recentScan']).total_seconds()) \
                    < self.repeated_scan_timeout:
                self.active_recordings[patient_id]['recentScan'] = datetime.now()
            else:
                self.stop_record(antenna, patient_id)

    def start_record(self, antenna, tag):
        self.antenna_cam_pair[antenna].start_record(tag)

    def stop_record(self, antenna, tag):
        print('the stop record tag in peripheral manager is', tag)
        if self.active_recordings[tag]['endTime'] is None:
            cam = self.antenna_cam_pair[self.active_recordings[tag]['startAntenna']]
            cam.stop_record(tag)
            self.active_recordings[tag]['endTime'] = datetime.now()
            self.active_recordings[tag]['exitAntenna'] = antenna

    # if tag is counted twice and it has been at least 5s since the last scan but less than timeout, stop recording and save to csv
    def check_for_double_scan(self, tag):
        if tag in self.active_recordings:
            if abs((datetime.now() - self.active_recordings[tag]['recentScan']).total_seconds()) \
                    < self.repeated_scan_timeout:
                self.stop_record(None, tag)
                self.df_history = self.df_history.append(self.active_recordings[tag], ignore_index=True)
                self.df_history.to_csv('output.csv', index=False)
                self.active_recordings.pop(tag, None)

    # if tag is detected multiple times within a short period, stop recording and save to csv
    def check_for_multiple_scans(self, tag):
        if tag in self.active_recordings:
            if abs((datetime.now() - self.active_recordings[tag]['recentScan']).total_seconds()) \
                    < self.repeated_scan_timeout:
                self.stop_record(None, tag)
                self.df_history = self.df_history.append(self.active_recordings[tag], ignore_index=True)
                self.df_history.to_csv('output.csv', index=False)
                self.active_recordings.pop(tag, None)

    # patient has more than 1 tag, check if both tags are in the active recordings and are named the same for the same participant
    # if so, wait for exit and save recording and history to csv
    def check_for_multiple_tags(self, tag1, tag2):
        if tag1 in self.active_recordings and tag2 in self.active_recordings:
            # check last 4 characters of tag[participantID] to see if they are the same
            if self.active_recordings[tag1]['participantTag'][-4:] == self.active_recordings[tag2]['participantTag'][-4:]:
                # wait for exit
                while self.active_recordings[tag1]['endTime'] is None or self.active_recordings[tag2]['endTime'] is None:
                    pass
                # check for double scan
                if abs((self.active_recordings[tag1]['endTime'] - self.active_recordings[tag2]['endTime']).total_seconds()) \
                        < self.repeated_scan_timeout:
                    self.stop_record(None, tag1)
                    self.stop_record(None, tag2)
                    self.df_history = self.df_history.append(self.active_recordings[tag1], ignore_index=True)
                    self.df_history = self.df_history.append(self.active_recordings[tag2], ignore_index=True)
                    self.df_history.to_csv('output.csv', index=False)
                    self.active_recordings.pop(tag1, None)
                    self.active_recordings.pop(tag2, None)

                # check for timeout
                elif abs((self.active_recordings[tag1]['endTime'] - self.active_recordings[tag2]['endTime']).total_seconds()) \
                        > self.cue_timeout:
                    self.stop_record(None, tag1)
                    self.stop_record(None, tag2)
                    self.df_history = self.df_history.append(self.active_recordings[tag1], ignore_index=True)
                    self.df_history = self.df_history.append(self.active_recordings[tag2], ignore_index=True)
                    self.df_history.to_csv('output.csv', index=False)
                    self.active_recordings.pop(tag1, None)
                    self.active_recordings.pop(tag2, None)

                # if both tags are cued, stop recording and save to csv
                elif self.active_recordings[tag1]['cued'] and self.active_recordings[tag2]['cued']:
                    self.stop_record(None, tag1)
                    self.stop_record(None, tag2)
                    self.df_history = self.df_history.append(self.active_recordings[tag1], ignore_index=True)
                    self.df_history = self.df_history.append(self.active_recordings[tag2], ignore_index=True)
                    self.df_history.to_csv('output.csv', index=False)
                    self.active_recordings.pop(tag1, None)
                    self.active_recordings.pop(tag2, None)


                # self.df_history = self.df_history.append(self.active_recordings[tag1], ignore_index=True)
                # self.df_history = self.df_history.append(self.active_recordings[tag2], ignore_index=True)
                # self.df_history.to_csv('output.csv', index=False)
                # self.active_recordings.pop(tag1, None)           
                # self.active_recordings.pop(tag2, None)


    # get tag, scan history, active recordings and antenna-cam pair info and return them
    def get_active_recordings(self):
        return self.active_recordings

    def get_df_history(self):
        return self.df_history

    def get_antenna_cam_pair(self):
        return self.antenna_cam_pair

    def get_ra_tags(self):
        return self.ra_tags

    def get_ra_tag_scan_time(self):
        return self.ra_tag_scan_time
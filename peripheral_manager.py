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
        self.cue_timeout = 5

        # timeout for how many times in a row a scan can be detected (caused by being near the scanner for too long)
        # for all scans to be considered as one scan
        self.repeated_scan_timeout = 3

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

from threading import Thread
from pubsub import pub
from datetime import datetime
from webcam import Webcam
import pandas as pd


class PeripheralManager:
    def __init__(self, timeout=30):
        self.camera1 = Webcam(0)
        self.camera2 = Webcam(1)

        # {antenna_number: webcam}
        self.antenna_cam_pair = {0: self.camera1, 1: self.camera1, 2: self.camera2, 3: self.camera2}
        self.timeout = timeout
        # {tag_number: {startTime: datetime, startAntenna: int, cued: bool, exitAntenna: int}}
        self.active_recordings = {}
        self.timeout_check_thread = Thread(target=self.threaded_timeout_check, daemon=True)
        self.ra_tags = [0, 2]
        self.ra_tag_scan_time = {self.camera1: datetime(1, 1, 1), self.camera2: datetime(1, 1, 1)}
        self.cue_timeout = 5
        self.repeated_scan_timeout = 0.5

        self.df_history = pd.DataFrame({'startTime': [],
                                        'startAntenna': [],
                                        'cued': [],
                                        'endTime': [],
                                        'exitAntenna': [],
                                        'recentScan': []
                                        })

        pub.subscribe(self.rfid_receiver, 'TagScan')

    def threaded_timeout_check(self):
        now = datetime.now()
        if self.active_recordings:
            for tag in self.active_recordings:
                if abs((now - self.active_recordings[tag]['startTime']).total_seconds()) > self.timeout:
                    self.stop_record(None, tag)

    def rfid_receiver(self, antenna, tag):
        print(f'Received scan from antenna {antenna}, tag {tag}')
        # since participants have 2 tags with consecutive numbers in each pair of pants, we will just use the odd number
        # NOTE: the odd number should be the smaller number in the numbering system for this to work

        # if it's an RA tag, change all the walks recorded by the respective camera to cued walks if the recording
        # has begun within 5s of the RA tag scan
        if tag in self.ra_tags:
            cam = self.antenna_cam_pair[antenna]
            self.ra_tag_scan_time[cam] = datetime.now()
            for recording in self.active_recordings:
                if self.antenna_cam_pair[recording['startAntenna']] == cam and \
                        abs(recording['startTime'] - datetime.now()) < self.cue_timeout:
                    recording['cued'] = True
            return

        if tag % 2 == 0:
            tag -= 1

        # if tag is not in the active recordings, add it and start recording
        if tag not in self.active_recordings:
            self.active_recordings[tag] = {'startTime': datetime.now(), 'startAntenna': antenna, 'cued': False,
                                           'endTime': None, 'exitAntenna': None, 'recentScan': datetime.now()}
            cam = self.antenna_cam_pair[antenna]
            if abs((self.ra_tag_scan_time[cam] - self.active_recordings[tag][
                'startTime']).total_seconds()) < self.cue_timeout:
                self.active_recordings[tag]['cued'] = True
            self.start_record(antenna, tag)

        else:
            # if the tag was recently scanned, we assume that the RFID has had a chance to scan it multiple times
            # before the participant can exit its range
            if abs((datetime.now() - self.active_recordings[tag][
                'recentScan']).total_seconds()) < self.repeated_scan_timeout:
                self.active_recordings[tag]['recentScan'] = datetime.now()
            else:
                self.stop_record(antenna, tag)

    def start_record(self, antenna, tag):
        self.antenna_cam_pair[antenna].start_record(tag)

    def stop_record(self, antenna, tag):
        print('the stop record tag in peripheral manager is', tag)
        cam = self.antenna_cam_pair[self.active_recordings[tag]['startAntenna']]
        cam.stop_record(tag)
        self.active_recordings[tag]['endTime'] = datetime.now()
        self.active_recordings[tag]['exitAntenna'] = antenna
        self.df_history = self.df_history.append(self.active_recordings[tag], ignore_index=True)
        self.active_recordings.pop(tag, None)
        self.df_history.to_csv('output.csv')


if __name__ == '__main__':
    pass

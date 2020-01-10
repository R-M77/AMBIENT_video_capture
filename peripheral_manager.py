from threading import Thread
from pubsub import pub
from datetime import datetime
from webcam import Webcam

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
        self.ra_tag_scan_time = {self.camera1: datetime.now(), self.camera2: datetime.now()}
        pub.subscribe(self.rfid_receiver, 'TagScan')

    def threaded_timeout_check(self):
        now = datetime.now()
        if self.active_recordings:
            for recording in self.active_recordings:
                if now - self.active_recordings[recording]['StartTime'] > self.timeout:
                    pass

    def rfid_receiver(self, antenna, tag):
        print(f'Received scan from antenna {antenna}, tag {tag}')
        # since participants have 2 tags with consecutive numbers in each pair of pants, we will just use the odd number
        # NOTE: the odd number should be the smaller number in the numbering system for this to work
        if tag % 2 == 0:
            tag -= 1

        # if tag is not in the active recordings, add it and start recording
        if tag not in self.active_recordings:
            self.active_recordings[tag] = {'startTime': datetime.now(), 'startAntenna': antenna, 'cued': False,
                                           'endTime': None, 'exitAntenna': None, 'recentScan': datetime.now()}
            self.start_record(tag)

        else:
            # if the tag was recently scanned, we assume that the RFID has had a chance to scan it multiple times
            # before the participant can exit its range
            if datetime.now() - self.active_recordings[tag]['recentScan'] < 3:
                self.active_recordings[tag]['recentScan'] = datetime.now()
            else:
                self.stop_record(tag)

    def start_record(self, tag):
        pass

    def stop_record(self, tag):
        pass

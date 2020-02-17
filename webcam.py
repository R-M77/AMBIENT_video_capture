import cv2
from threading import Thread
import numpy as np
from datetime import datetime
from pathlib import Path
import os
import time
from time import sleep
from pprint import pprint


class Webcam:
    def __init__(self, cam_id, display_image=True):
        self.cam_id = cam_id
        self.cap = cv2.VideoCapture(cam_id)
        self.display_image = display_image
        # set thread daemon to True to close when main code closes
        self.t = Thread(target=self.threaded_capture, daemon=True)
        self.frame = np.zeros((480, 640, 3), dtype='uint8')
        self.vid_captures = {}
        self.vid_cod = cv2.VideoWriter_fourcc(*'XVID')
        self.parent_dir = os.path.join(os.path.expanduser('~'), 'Desktop/AMBIENT videos')
        Path(self.parent_dir).mkdir(parents=True, exist_ok=True)
        self.t.start()

    def threaded_capture(self):
        while True:
            ret, self.frame = self.cap.read()
            if not ret:
                continue
            # cv2.imshow(f'camera {self.cam_id}', self.frame)
            if self.vid_captures:
                for tag in self.vid_captures:
                    self.vid_captures[tag].write(self.frame)

            # if cv2.waitKey(1) & 0xFF == ord('q'):
                # break
        self.cap.release()

    def start_record(self, tag_id):
        self.create_date_folder()
        file_name = self.generate_file_path(tag_id)
        output = cv2.VideoWriter(file_name, self.vid_cod, 30.0, (640, 480))
        self.vid_captures[tag_id] = output
        print('at start:')
        pprint(self.vid_captures)
        pass

    def stop_record(self, tag_id):
        try:
            self.vid_captures[tag_id].release()
            self.vid_captures.pop(tag_id, None)
        except KeyError:
            print('key error:', tag_id)

    def generate_file_path(self, tag_id):
        folder_path = self.create_date_folder()
        date_time_string = datetime.now().strftime('%Y-%m-%d %H-%M-%S')
        file_name = f'{date_time_string}-ID-{tag_id}.avi'
        file_path = os.path.join(folder_path, file_name)
        return file_path

    def create_date_folder(self):
        date = datetime.now().strftime('%Y-%m-%d')
        folder_path = os.path.join(self.parent_dir, date)
        print(folder_path)
        Path(folder_path).mkdir(parents=True, exist_ok=True)
        return folder_path


if __name__ == '__main__':
    cam1 = Webcam(0)
    cam2 = Webcam(2)
    sleep(1)
    cam1.start_record(5)
    cam1.start_record(8)
    cam2.start_record(16)
    sleep(2)
    cam1.stop_record(8)
    sleep(1)
    cam2.stop_record(16)
    sleep(2)
    cam1.stop_record(5)

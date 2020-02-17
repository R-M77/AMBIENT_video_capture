import cv2
from threading import Thread
import numpy as np
from datetime import datetime
from pathlib import Path
import os
import time
from time import sleep
from pprint import pprint
from queue import Queue

class Webcam:
    def __init__(self, cam_id):
        self.cam_id = cam_id
        self.cap = cv2.VideoCapture(cam_id)
        self.q = Queue()

        self.vid_captures = {}
        self.vid_cod = cv2.VideoWriter_fourcc(*'XVID')
        self.parent_dir = os.path.join(os.path.expanduser('~'), 'Desktop/AMBIENT videos')
        Path(self.parent_dir).mkdir(parents=True, exist_ok=True)

        # set thread daemon to True to close when main code closes
        self.capture_thread = Thread(target=self.threaded_capture, daemon=True)
        self.writer_thread = Thread(target=self.threaded_write, daemon=True)
        self.capture_thread.start()
        self.writer_thread.start()

    def threaded_capture(self):
        prev_time = time.time()
        while True:
            ret, frame = self.cap.read()
            if not ret:
                print('emtpy frame')
                continue
            self.q.put(frame)
            print(f'FPS {self.cam_id}: {1.0/(time.time() - prev_time)}')
            prev_time = time.time()
        self.cap.release()

    def threaded_write(self):
        while True:
            if not self.q.empty():
                frame = self.q.get()
                if self.vid_captures:
                    for tag in self.vid_captures:
                        self.vid_captures[tag].write(frame)


    def start_record(self, tag_id):
        self.create_date_folder()
        file_name = self.generate_file_path(tag_id)
        print(file_name)
        output = cv2.VideoWriter(file_name, self.vid_cod, 15.0, (640, 480))
        self.vid_captures[tag_id] = output
        print('Video captures:')
        pprint(self.vid_captures)

    def stop_record(self, tag_id):
        try:
            self.vid_captures[tag_id].release()
            self.vid_captures.pop(tag_id, None)
            print('Video captures:')
            pprint(self.vid_captures)
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
        Path(folder_path).mkdir(parents=True, exist_ok=True)
        return folder_path


if __name__ == '__main__':
    cam1 = Webcam(2)
#     cam2 = Webcam(2)
    sleep(1)
    cam1.start_record(20)
    sleep(5)
    cam1.stop_record(20)
#     cam2.stop_record(18)

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
import paramiko


class PiCamera:
    def __init__(self, cam_id):
        # self.cap = cv2.VideoCapture(0, cv2.CAP_DSHOW)
        self.cap = cv2.VideoCapture(cam_id)
        self.FRAME_WIDTH = 640
        self.FRAME_HEIGHT = 480
        self.FRAME_RATE = 30 # match with camera fps
        self.cap.set(cv2.CAP_PROP_FPS, self.FRAME_RATE)
        self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, self.FRAME_WIDTH)
        self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, self.FRAME_HEIGHT)

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

    # thread to capture frames from camera
    def threaded_capture(self):
        prev_time = time.time()
        while True:
            ret, frame = self.cap.read()
            now = time.time()
            # print(f'duration: {now - prev_time}')
            # print(f'FPS: {1.0/(now - prev_time)}')
            prev_time = now

            if not ret:
                print('emtpy frame')
                continue
            self.q.put(frame)
        self.cap.release()

    # thread to write frames to video file
    def threaded_write(self):
        while True:
            sleep(0.001)
            if not self.q.empty():
                frame = self.q.get()
                if self.vid_captures:
                    for tag in self.vid_captures:
                        self.vid_captures[tag].write(frame)

    # start recording and save video file to folder
    def start_record(self, tag_id):
        self.create_date_folder()
        file_name = self.generate_file_path(tag_id)
        print(file_name)
        output = cv2.VideoWriter(file_name, self.vid_cod, self.FRAME_RATE, (self.FRAME_WIDTH, self.FRAME_HEIGHT))
        self.vid_captures[tag_id] = output
        print(f'Camera video captures:')
        pprint(self.vid_captures)

    # stop recording and transfer video file to Ubuntu PC
    # --- using scp command over LAN connection ---
    # --- replace username and IP address ---
    # def stop_record(self, tag_id):
    #     try:
    #         self.vid_captures[tag_id].release()
    #         self.vid_captures.pop(tag_id, None)
    #         print(f'Camera video captures:')
    #         pprint(self.vid_captures)
    #         # add code to transfer video file to Ubuntu PC
    #         file_path = self.generate_file_path(tag_id)
    #         # os.system(f'scp {file_path} <ubuntu-username>@<ubuntu-IP-address>:/path/to/save/')
    #     except KeyError:
    #         print('key error:', tag_id)

    # stop recording and transfer video file to Ubuntu PC
    # --- using paramiko SSH ---
    def stop_record(self, tag_id):
        try:
            self.vid_captures[tag_id].release()
            self.vid_captures.pop(tag_id, None)
            print(f'Camera {self.cam_id} video captures:')
            pprint(self.vid_captures)

            # Transfer the video file to the Ubuntu PC using LAN connection
            file_path = self.generate_file_path(tag_id)
            self.transfer_file_to_ubuntu(file_path)

        except KeyError:
            print('key error:', tag_id)

    # Transfer the video file to the Ubuntu PC using LAN connection 
    # --- using paramiko SSH ---
    def transfer_file_to_ubuntu(self, file_path):
        # Set up the SSH client
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())

        # Connect to the Ubuntu PC
        ip_addr = '192.168.0.100'  # Replace with your Ubuntu PC's IP address
        username = 'ubuntuuser'  # Replace with your Ubuntu PC's username
        password = 'ubuntu_password'  # Replace with your Ubuntu PC's password
        ssh.connect(ip_addr, username=username, password=password)

    # generate file path for video file
    def generate_file_path(self, tag_id):
        folder_path = self.create_date_folder()
        date_time_string = datetime.now().strftime('%Y-%m-%d %H-%M-%S')
        file_name = f'{date_time_string}-ID-{tag_id}.avi'
        file_path = os.path.join(folder_path, file_name)
        return file_path

    # create folder for video file
    def create_date_folder(self):
        date = datetime.now().strftime('%Y-%m-%d')
        folder_path = os.path.join(self.parent_dir, date)
        Path(folder_path).mkdir(parents=True, exist_ok=True)
        return folder_path
    
# test code
# if __name__ == '__main__':
#     pi_cam1 = PiCamera(0) # 0 for webcam, 1 for USB camera
#     pi_cam2 = PiCamera(1) 
#     while True:
#         sleep(1)
#         pi_cam.start_record('123')
#         sleep(5)
#         pi_cam.stop_record('123')

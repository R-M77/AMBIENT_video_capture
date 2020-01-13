import face_recognition
import os
import cv2
import pickle

encodings = []
folder_path = r'D:\facial detection'

for name in os.listdir(folder_path):
    person_path = os.path.join(folder_path, name)
    for img_path in os.listdir(person_path):
        img = cv2.imread(img_path)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        boxes = face_recognition.face_locations(img, model="cnn")
        encodings = face_recognition.face_encodings(img, boxes)


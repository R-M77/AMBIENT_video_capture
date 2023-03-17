import requests

# URL of the PC Flask server
url = 'http://192.168.2.17:9002/start_record'

# Code to read RFID tag ID and send signal to PC to start recording
# ...

# When tag is detected, send signal to PC to start recording
response = requests.post(url)
if response.status_code == 200:
    print('Record started on PC')
else:
    print('Error starting record on PC')

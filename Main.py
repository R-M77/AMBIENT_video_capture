from webcam import Webcam
from OBID_UHF_scanner import TagScanner
from peripheral_manager import PeripheralManager
import pubsub as pub
from time import sleep
from datetime import datetime
import pandas as pd
from queue import Queue

scanner = TagScanner()
manager = PeripheralManager()
startTime = datetime.now()
duration = 0
scenario = pd.read_csv('scenario.csv')

while True:
    duration = (datetime.now() - startTime).total_seconds()
    for i, row in scenario.iterrows():
        if row['time'] < duration:
            print(row)
            scanner.simulate_scan(row['antenna'], row['tag'])
            scenario.drop(i, inplace=True)

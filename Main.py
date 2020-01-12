from webcam import Webcam
from OBID_UHF_scanner import TagScanner
from peripheral_manager import PeripheralManager
import pubsub as pub
from time import sleep
from datetime import datetime
import pandas as pd

scanner = TagScanner()
manager = PeripheralManager()
startTime = datetime.now()
duration = 0
# scenario = pd.DataFrame('scenario.xlsx')

while True:
    duration = datetime.now() - startTime
    scanner.simulate_scan(1, 5)
    scanner.simulate_scan(1, 18)
    sleep(2)
    scanner.simulate_scan(3, 18)
    sleep(1)
    scanner.simulate_scan(3, 5)
    sleep(0.5)
    break

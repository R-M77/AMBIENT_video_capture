from webcam import Webcam
from OBID_UHF_scanner import TagScanner
from peripheral_manager import PeripheralManager
import pubsub as pub
from time import sleep
from datetime import datetime

scanner = TagScanner()
manager = PeripheralManager()
startTime = datetime.now()
duration = 0

while True:
    duration = datetime.now() - startTime
    scanner.simulate_scan(1, 5)
    sleep(10)
    scanner.simulate_scan(3, 5)
    sleep(5)
    break

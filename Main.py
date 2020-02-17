from webcam import Webcam
from OBID_UHF_scanner import TagScanner
from peripheral_manager import PeripheralManager
from time import sleep

scanner = TagScanner()
manager = PeripheralManager()

while True:
    sleep(10)

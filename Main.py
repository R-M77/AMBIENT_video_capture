from webcam import Webcam
from OBID_UHF_scanner import TagScanner
from peripheral_manager import PeripheralManager
import pubsub as pub
from time import sleep

scanner = TagScanner()
manager = PeripheralManager()
sleep(5)


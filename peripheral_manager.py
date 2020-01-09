from threading import Thread
from pubsub import pub

class PeripheralManager:
    def __init__(self):
        pub.subscribe(self.rfid_receiver, 'TagScan')

    def rfid_receiver(self, antenna, tag):
        print(f'Antenna: {antenna}, Tag: {tag}')
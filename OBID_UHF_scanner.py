import sys
import usb.core
import usb.util
from threading import Thread
from pubsub import pub
from time import sleep
from queue import Queue


class TagScanner:
    def __init__(self):
        # self.t = Thread(target=self.threaded_simulated_scan, daemon=True)
        self.usb_keyboard = UsbKeyboard()
        self.t = Thread(target=self.threaded_scan, daemon=True)
        self.q = Queue()
        self.t.start()

    def threaded_scan(self):
        while True:
            sleep(1)
            if not self.usb_keyboard.q.empty():
                antenna_number, patient_id = self.usb_keyboard.q.get()
                pub.sendMessage('TagScan', antenna=antenna_number, patient_id=patient_id)

    def threaded_simulated_scan(self):
        while True:
            if not self.q.empty():
                antenna_number, patient_id = self.q.get()
                pub.sendMessage('TagScan', antenna=antenna_number, patient_id=patient_id)

            sleep(0.1)

    def simulate_scan(self, antenna, patient_id):
        self.q.put((antenna, patient_id))


class UsbKeyboard:
    def __init__(self):

        self.key_map = ['', '', '', '',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '\n', '^]', '^H',
        '^I', ' ', '-', '=', '[', ']', '\\', '>', ';', "'", '`', ',', '.',
        '/', 'CapsLock', 'F1', 'F2', 'F3', 'F4', 'F5', 'F6', 'F7', 'F8', 'F9', 'F10', 'F11', 'F12',
        'PS', 'SL', 'Pause', 'Ins', 'Home', 'PU', '^D', 'End', 'PD', '->', '<-', '-v', '-^', 'NL',
        'KP/', 'KP*', 'KP-', 'KP+', 'KPE', 'KP1', 'KP2', 'KP3', 'KP4', 'KP5', 'KP6', 'KP7', 'KP8',
        'KP9', 'KP0', '\\', 'App', 'Pow', 'KP=', 'F13', 'F14']

        self.dev = usb.core.find(idVendor=2737, idProduct=2)
        self.interface = 1
        self.endpoint = self.dev[0][(self.interface, 0)][0]

        if self.dev.is_kernel_driver_active(self.interface):
            self.dev.detach_kernel_driver(self.interface)

        usb.util.claim_interface(self.dev, self.interface)

        self.q = Queue()
        self.t = Thread(target=self.threaded_scan, daemon=True)
        self.t.start()

    def threaded_scan(self):
        data_buffer = ''
        while True:
            try:
                data_raw = self.dev.read(self.endpoint.bEndpointAddress, self.endpoint.wMaxPacketSize)
                data = self.key_map[data_raw[2]]
                data_buffer += data

                if data == '\n':
                    print('data:', data_buffer.strip())
                    if len(data_buffer) != 27:
                        print('invalid tag data length')
                    elif data_buffer[:8] == '00000000' and data_buffer[16:24] == '65776642':
                        antenna_number = int(data_buffer[24:26])
                        patient_id = int(data_buffer[8:12])
                        tag_number = int(data_buffer[12:16])
                        print('antenna number:', antenna_number)
                        print('patient id:', patient_id)
                        print('tag number:', tag_number)

                        self.q.put((antenna_number, patient_id))
                    else:
                        print('invalid ambient tag number')

                    print('')
                    data_buffer = ''

            except usb.core.USBError as e:
                data_raw = None
                if 'Operation timed out' in e.args:
                    continue
                else:
                    print(e)

        usb.util.release_interface(self.dev, self.interface)
        self.dev.attach_kernel_driver(self.interface)

'''
def listener(antenna, patient_id):
    print(f'Antenna: {antenna}, Patient ID: {patient_id}')


if __name__ == '__main__':
    usb_keyboard = UsbKeyboard()

    while True:
        sleep(0.1)

    scanner = TagScanner()
    pub.subscribe(listener, 'TagScan')
    scanner.simulate_scan(2, 4)
    sleep(1)
    scanner.simulate_scan(4, 14)
    scanner.simulate_scan(6, 423)
    scanner.simulate_scan(287, 4324)
    sleep(2)
    scanner.simulate_scan(1, 40)
    sleep(1)
    scanner.simulate_scan(25645, 121)
    scanner.simulate_scan(12, 5660)
    sleep(3)
'''

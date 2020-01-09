from threading import Thread
from pubsub import pub
from time import sleep


class TagScanner:
    def __init__(self):
        self.t = Thread(target=self.threaded_scan, daemon=True)
        self.t.start()

    def threaded_scan(self):
        while True:
            print('in thread')
            antenna_number = None
            tag_number = None
            # antenna_number, tag_number = read_something()
            antenna_number = 1
            tag_number = 42
            if antenna_number is not None:
                pub.sendMessage('TagScan', antenna=antenna_number, tag=tag_number)

            sleep(2)


def listener(antenna, tag):
    print(f'Antenna: {antenna}, Tag: {tag}')

if __name__ == '__main__':
    scanner = TagScanner()
    pub.subscribe(listener, 'TagScan')
    sleep(5)

from threading import Thread
from pubsub import pub
from time import sleep
from queue import Queue


class TagScanner:
    def __init__(self):
        self.t = Thread(target=self.threaded_scan, daemon=True)
        self.q = Queue()
        self.t.start()

    def threaded_scan(self):
        while True:
            if not self.q.empty():
                antenna_number, tag_number = self.q.get()
                pub.sendMessage('TagScan', antenna=antenna_number, tag=tag_number)

            sleep(0.1)

    def simulate_scan(self, antenna, tag):
        self.q.put((antenna, tag))


def listener(antenna, tag):
    print(f'Antenna: {antenna}, Tag: {tag}')


if __name__ == '__main__':
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

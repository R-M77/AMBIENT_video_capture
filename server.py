from flask import Flask, request
from peripheral_manager import PeripheralManager

app = Flask(__name__)
pm = PeripheralManager()

@app.route('/start_record', methods=['POST'])
def start_record():
    pm.start_record()
    return 'Record started'

if __name__ == '__main__':
    app.run(host='192.168.2.17', port=9002)


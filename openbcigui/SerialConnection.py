from PyQt5.QtCore import QThread

import serial

class SerialConnection(QThread):
    def __init__(self, markers):
        super().__init__()

        self.markers = markers
        self.port = serial.Serial('COM3')

    def run(self):
        while True:
            res = int.from_bytes(self.port.read(), "big")
            self.markers[len(self.markers) - 1] = res

    def addMarker(self):
        self.markers.append(0);

    def setMarkers(self, newMarkers):
        self.markers = newMarkers

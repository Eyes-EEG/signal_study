from PyQt5.QtCore import QThread

from pyOpenBCI import OpenBCICyton
from pylsl import StreamInfo, StreamOutlet

from SerialConnection import SerialConnection

import numpy as np

class OpenBCIConnection(QThread):
    def __init__(self, eegValues, plotFigure, markers):
        super().__init__()

        self.SCALE_FACTOR_EEG = (4500000)/24/(2**23-1) # uV/count
        self.SCALE_FACTOR_AUX = 0.002 / (2**4)

        self.sendLSL = False
        self.eegValues = eegValues
        self.serialConnection = SerialConnection(markers)
        self.board = OpenBCICyton(port='COM7', daisy=True)

        self.plotFigure = plotFigure;

    def run(self):
        self.serialConnection.start()

        if self.sendLSL:
            self.lslStream()
        else:
            self.acquiringData()

    def acquiringData(self):
        self.board.start_stream(self.acquireData)

    def acquireData(self, sample):
        # print(sample.channels_data)

        for i in range(len(sample.channels_data)):
            self.eegValues[i].append(sample.channels_data[i] * self.SCALE_FACTOR_EEG)
        self.serialConnection.addMarker()

        self.plotFigure.updateData()

    def lslStream(self):
        print("Creating LSL stream for EEG. \nName: OpenBCIEEG\nID: OpenBCItestEEG\n")

        infoEEG = StreamInfo('OpenBCIEEG', 'EEG', 16, 250, 'float32', 'OpenBCItestEEG')

        print("Creating LSL stream for AUX. \nName: OpenBCIAUX\nID: OpenBCItestEEG\n")

        infoAux = StreamInfo('OpenBCIAUX', 'AUX', 3, 250, 'float32', 'OpenBCItestAUX')

        self.outletEEG = StreamOutlet(infoEEG)
        self.outletAux = StreamOutlet(infoAux)

        self.board.start_stream(self.lslStreamers)

    def lslStreamers(self, sample):
        # print(sample.channels_data)

        self.outletEEG.push_sample(np.array(sample.channels_data) * self.SCALE_FACTOR_EEG)
        self.outletAux.push_sample(np.array(sample.aux_data) * self.SCALE_FACTOR_AUX)
        self.serialConnection.addMarker()

        self.plotFigure.updateData()

    def getSendLSL(self):
        return self.sendLSL;

    def setSendLSL(self, value):
        self.sendLSL = value;

    def setMarkers(self, newMarkers):
        self.serialConnection.setMarkers(newMarkers)

    def setEEGValues(self, newEEGValues):
        self.eegValues = newEEGValues

    def stop(self):
        self.board.stop_stream()

    def disconnect(self):
        self.board.disconnect()

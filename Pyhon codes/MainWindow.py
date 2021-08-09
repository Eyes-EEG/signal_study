from window_ui import *
from OpenBCIConnection import OpenBCIConnection

from EEGPlot import EEGPlot
from datetime import datetime

import os
import numpy as np

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self, *args, **kwargs):
        QtWidgets.QMainWindow.__init__(self, *args, **kwargs)
        self.setupUi(self)

        self.lslStatusLabel.setText("Desactivated")
        self.lslButton.setEnabled(False)
        self.acquiringButton.setEnabled(False)

        self.connectButton.clicked.connect(self.connect)
        self.acquiringButton.clicked.connect(self.acquireData)
        self.lslButton.clicked.connect(self.changeLSLStatus)

        self.connected = False
        self.eegValues = self.createNewList()
        self.openBCIConnection = None

        self.markers = list(np.zeros(10))

        self.plotFigure = EEGPlot(self.graphWidget, self.eegValues)

    def connect(self):
        self.openBCIConnection = OpenBCIConnection(self.eegValues, self.plotFigure, self.markers)
        self.openBCIConnection.finished.connect(self.acquisitionFinished)
        self.connectButton.setEnabled(False)
        self.lslButton.setEnabled(True)
        self.acquiringButton.setEnabled(True)

    def acquireData(self):
        self.programStatuslabel.setText("Acquiring data...")
        self.lslButton.setEnabled(False)
        self.initializeConnection()

    def changeLSLStatus(self):
        if self.openBCIConnection.getSendLSL() == True:
            self.openBCIConnection.setSendLSL(False)
            self.lslStatusLabel.setText("Desactivated")
        else:
            self.openBCIConnection.setSendLSL(True)
            self.lslStatusLabel.setText("Activated")

    def initializeConnection(self):
        if self.connected == False:
            self.openBCIConnection.start()
            self.connected = True

        else:
            self.openBCIConnection.stop()
            self.connected = False

    def acquisitionFinished(self):
        self.programStatuslabel.setText("Connection finished!")
        self.lslButton.setEnabled(True)
        self.deleteConnection()

        self.saveFile()

        self.openBCIConnection.setEEGValues(self.createNewList())
        self.openBCIConnection.setMarkers(list(np.zeros(10)));

    def deleteConnection(self):
        self.openBCIConnection.stop()

    def createNewList(self):
        eegValues = list()

        for i in range(16):
            eegValues.append(list(np.zeros(10)))

        return eegValues

    def saveFile(self):
        now = datetime.now()

        folder = 'records/'
        fileName = now.strftime(folder + '%Y%d%m_%H%M%S.csv')

        if not os.path.isdir(folder):
            try:
                os.mkdir(folder)
            except OSError:
                print ("Creation of the directory %s failed" % folder)

        with open(fileName, 'w') as file:

            for i in range(len(self.eegValues)):
                values = ', '.join(map(str, self.eegValues[i]))
                file.write(values)
                file.write('\n')

            file.write(', '.join(map(str, self.markers)))

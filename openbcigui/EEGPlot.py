from PyQt5.QtCore import QThread

import pyqtgraph as pg
import numpy as np

class EEGPlot():
    def __init__(self, graphWidget, eegValues):
        self.plotFigure = graphWidget
        self.eegValues = eegValues

        self.visualSignals = list()

        # create plot
        self.plotFigure.showGrid(x=True, y=True)
        self.plotFigure.addLegend()

        self.xAxis = list(range(0, 10))
        lenSaved = len(self.eegValues[1])
        for i in range(len(self.eegValues)):
            self.visualSignals.append(self.plotFigure.plot(self.xAxis, self.eegValues[1][lenSaved - 10: lenSaved]))

        # set properties
        self.plotFigure.setLabel('left', 'Value', units='V')
        self.plotFigure.setLabel('bottom', 'Time', units='s')
        self.plotFigure.setXRange(0, 10)
        self.plotFigure.setYRange(-10, 10)
        self.plotFigure.setWindowTitle('pyqtgraph plot')

    def updateData(self):
        lenSaved = len(self.eegValues[1])
        tmpEEGValues = list()
        for i in range(len(self.eegValues)):
            tmpEEGValues.append(self.eegValues[i][lenSaved - 10 : lenSaved])

        matrix = np.array(tmpEEGValues)
        mean = np.mean(matrix, axis=0)

        numSignals = len(self.visualSignals)

        globalMax = -float("inf")
        globalMin = float("inf")
        for i in range(numSignals):
            eegToShow = matrix[i] + ((i + 1) * mean)

            self.visualSignals[i].setData(self.xAxis, eegToShow)

            if (np.amax(eegToShow) > globalMax):
                globalMax = np.amax(eegToShow)

            if (np.amin(eegToShow) < globalMin):
                globalMin = np.amin(eegToShow)

        self.plotFigure.setYRange(globalMin - np.amin(mean), globalMax + np.amax(mean))

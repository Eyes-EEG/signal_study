# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'window.ui'
#
# Created by: PyQt5 UI code generator 5.13.0
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.acquiringButton = QtWidgets.QPushButton(self.centralwidget)
        self.acquiringButton.setGeometry(QtCore.QRect(220, 530, 75, 23))
        self.acquiringButton.setObjectName("acquiringButton")
        self.programStatuslabel = QtWidgets.QLabel(self.centralwidget)
        self.programStatuslabel.setGeometry(QtCore.QRect(220, 500, 181, 20))
        self.programStatuslabel.setText("")
        self.programStatuslabel.setObjectName("programStatuslabel")
        self.verticalLayoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(-1, -1, 801, 491))
        self.verticalLayoutWidget.setObjectName("verticalLayoutWidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.lslButton = QtWidgets.QPushButton(self.centralwidget)
        self.lslButton.setGeometry(QtCore.QRect(420, 530, 75, 23))
        self.lslButton.setObjectName("lslButton")
        self.connectButton = QtWidgets.QPushButton(self.centralwidget)
        self.connectButton.setGeometry(QtCore.QRect(20, 530, 75, 23))
        self.connectButton.setObjectName("connectButton")
        self.lslStatusLabel = QtWidgets.QLabel(self.centralwidget)
        self.lslStatusLabel.setGeometry(QtCore.QRect(420, 500, 181, 20))
        self.lslStatusLabel.setText("")
        self.lslStatusLabel.setObjectName("lslStatusLabel")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.acquiringButton.setText(_translate("MainWindow", "Acquire"))
        self.lslButton.setText(_translate("MainWindow", "LSL"))
        self.connectButton.setText(_translate("MainWindow", "Connect"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

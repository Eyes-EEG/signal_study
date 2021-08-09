#-------------------------------------------------
#
# Project created by QtCreator 2018-09-20T12:03:27
#
#-------------------------------------------------

QT       += core gui widgets
QT       += multimedia

TARGET = BrainSignalSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    BasalProtocolUI.cpp \
    GeneralDataUI.cpp \
    Audio.cpp \
    Image.cpp \
    ProtocolUI.cpp \
    ProtocolsUI.cpp \
    StimuliRenderingUI.cpp \
    StimuliScreen.cpp \
    Stimulus.cpp \
    StimuliRendering.cpp \
    StimuliProtocolUI.cpp \
    AudioProtocolUI.cpp \
    ImageProtocolUI.cpp \
    ControlPanelStimuliScreenUI.cpp \
    StimuliMenuUI.cpp \
    ProtocolSettings.cpp \
    Protocol.cpp \
    DataLogUI.cpp

HEADERS += \
    Audio.h \
    BasalProtocolUI.h \
    Image.h \
    ProtocolUI.h \
    ProtocolsUI.h \
    StimuliMenuUI.h \
    StimuliRenderingUI.h \
    StimuliScreen.h \
    Stimulus.h \
    StimuliProtocolUI.h \
    StimuliRendering.h \
    AudioProtocolUI.h \
    ImageProtocolUI.h \
    ControlPanelStimuliScreenUI.h \
    Protocol.h \
    ProtocolSettings.h \
    DataLogUI.h \
    GeneralDataUI.h \
    Markers.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    img.qrc \
    sounds.qrc

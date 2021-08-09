#include "Image.h"

Image::Image(StimuliScreen* stimuliScreen, int marker, QString path, int actionTime, int durationTime) :
    Stimulus (marker, path, actionTime, durationTime) {

    this -> stimuliScreen = stimuliScreen;
}

Image::~Image() {}

void Image::run (DataLogUI* dataLogUI) {
    if(!getIsShowed()) {
        QMetaObject::invokeMethod(getStimuliScreen(),
                                  "updateImage",
                                  Qt::QueuedConnection,
                                  Q_ARG(QString, this -> getPath()));
        active(dataLogUI);
    }
}

void Image::stop(DataLogUI* dataLogUI) {
    if(!getIsStopped()) {
        getStimuliScreen() -> clear();
        desactive(dataLogUI);
    }
}

StimuliScreen* Image::getStimuliScreen() const {
    return stimuliScreen;
}

void Image::setStimuliScreen(StimuliScreen *value) {
    stimuliScreen = value;
}

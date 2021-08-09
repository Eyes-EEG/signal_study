#include "Stimulus.h"

Stimulus::Stimulus() {}

Stimulus::Stimulus(int marker, QString path, int actionTime, int durationTime) {
    this -> isShowed = false;
    this -> isStopped = false;
    this -> marker = marker;
    this -> path = path;
    this -> actionTime = actionTime;
    this -> durationTime = durationTime;
}

Stimulus::~Stimulus() {}

void Stimulus::sendSignal() {
    QProcess*   process = new QProcess();
    QString program = "/path/to/file/.exe " + QString::number(getMarker());
    process -> start(program);
}

void Stimulus::active(DataLogUI* dataLogUI) {
    setIsShowed(true);
    sendSignal();

    QMetaObject::invokeMethod(dataLogUI,
                              "addStimulusLog",
                              Qt::QueuedConnection,
                              Q_ARG(int, this -> getMarker()),
                              Q_ARG(bool, true));
}

void Stimulus::desactive(DataLogUI* dataLogUI) {
    setIsStopped(true);
    sendSignal();

    QMetaObject::invokeMethod(dataLogUI,
                              "addStimulusLog",
                              Qt::QueuedConnection,
                              Q_ARG(int, this -> getMarker()),
                              Q_ARG(bool, false));
}

int Stimulus::getActionTime() const {
    return actionTime;
}

void Stimulus::setActionTime(int value) {
    actionTime = value;
}

int Stimulus::getDurationTime() const {
    return durationTime;
}

void Stimulus::setDurationTime(int value) {
    durationTime = value;
}

QString Stimulus::getPath() const {
    return path;
}

void Stimulus::setPath(QString value){
    path = value;
}

bool Stimulus::getIsShowed() const {
    return isShowed;
}

void Stimulus::setIsShowed(bool value) {
    isShowed = value;
}

bool Stimulus::getIsStopped() const {
    return isStopped;
}

void Stimulus::setIsStopped(bool value) {
    isStopped = value;
}

int Stimulus::getMarker() const {
    return marker;
}

void Stimulus::setMarker(int value) {
    marker = value;
}

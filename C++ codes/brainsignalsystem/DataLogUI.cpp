#include "DataLogUI.h"

DataLogUI::DataLogUI(QWidget *parent) : QWidget(parent) {
    this -> eventLogs = new QVBoxLayout();

    setUpdatesEnabled(true);

    setLayout(eventLogs);
    showText(new QString("\tLogs:\n\n"));
}

DataLogUI::~DataLogUI() {}

void DataLogUI::addStimulusLog(int stimulusIndex, bool state) {

    QString* text = getStimulusName(stimulusIndex);

    QString* stateText = nullptr;
    if(state) {
        stateText = new QString("Activate");
    } else {
        stateText = new QString("Desactivate");
    }

    QString time = QTime::currentTime().toString();

    QString totalText = *(text) + " " + *(stateText) + " " + time;

    showText(&totalText);
}

void DataLogUI::showText(QString* text) {
    QLabel* event = new QLabel(*text);
    getEventLogs() -> addWidget(event);

    this -> adjustSize();
}

QString* DataLogUI::getStimulusName(int marker) {
    switch (marker) {
        case (Neutral): {
            return new QString("Neutral");
        }

        case (OpenCloseEyes): {
            return new QString("Open close eyes");
        }

        case (RightArrow): {
            return new QString("Right");
        }

        case (LeftArrow): {
            return new QString("Left");
        }

        case (DownArrow): {
            return new QString("Down");
        }

        case (UpArrow): {
            return new QString("Up");
        }
    }
}

QVBoxLayout* DataLogUI::getEventLogs() const {
    return eventLogs;
}

void DataLogUI::setEventLogs(QVBoxLayout* value) {
    eventLogs = value;
}

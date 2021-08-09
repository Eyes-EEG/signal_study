#include "ProtocolSettings.h"

ProtocolSettings::ProtocolSettings(int type, int basalStimulusTime, int numberOfStimuli, int stimuliTime, int timeBetweenStimuli, bool aleatory, QList<int> stimuliList) {
    this -> type = type;
    this -> basalStimulusTime = basalStimulusTime;
    this -> numberOfStimuli = numberOfStimuli;
    this -> stimuliTime = stimuliTime;
    this -> timeBetweenStimuli = timeBetweenStimuli;
    this -> aleatory = aleatory;
    this -> stimuliList = stimuliList;
}

ProtocolSettings::~ProtocolSettings() {}

int ProtocolSettings::getBasalStimulusTime() const {
    return basalStimulusTime;
}

void ProtocolSettings::setBasalStimulusTime(int value) {
    basalStimulusTime = value;
}

int ProtocolSettings::getNumberOfStimuli() const {
    return numberOfStimuli;
}

void ProtocolSettings::setNumberOfStimuli(int value) {
    numberOfStimuli = value;
}

int ProtocolSettings::getStimuliTime() const {
    return stimuliTime;
}

void ProtocolSettings::setStimuliTime(int value) {
    stimuliTime = value;
}

int ProtocolSettings::getTimeBetweenStimuli() const {
    return timeBetweenStimuli;
}

void ProtocolSettings::setTimeBetweenStimuli(int value) {
    timeBetweenStimuli = value;
}

int ProtocolSettings::getType() const {
    return type;
}

void ProtocolSettings::setType(int value) {
    type = value;
}

bool ProtocolSettings::getAleatory() const {
    return aleatory;
}

QList<int> ProtocolSettings::getStimuliList() const {
    return stimuliList;
}

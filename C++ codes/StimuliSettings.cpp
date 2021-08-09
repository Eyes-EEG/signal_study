#include "StimuliSettings.h"

StimuliSettings::StimuliSettings() {
    stimulusTime = 34000;
}

StimuliSettings::~StimuliSettings() {}

int StimuliSettings::getStimuliTime() const {
    return stimulusTime;
}

void StimuliSettings::setStimuliTime(int value) {
    stimulusTime = value;
}

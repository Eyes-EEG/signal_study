#ifndef STIMULUSSETTINGS_H
#define STIMULUSSETTINGS_H

#include <QList>

#include "Stimulus.h"

class StimuliSettings {
    private:
        int stimulusTime;

    public:
        StimuliSettings();
        ~StimuliSettings();

        int getStimuliTime() const;
        void setStimuliTime(int value);
};

#endif // STIMULUSSETTINGS_H

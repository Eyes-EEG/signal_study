#ifndef PROTOCOLSETTINGS_H
#define PROTOCOLSETTINGS_H

#include <QList>

#include "Markers.h"

class ProtocolSettings {
    private:
        int type;
        int basalStimulusTime;
        int numberOfStimuli;
        int stimuliTime;
        int timeBetweenStimuli;
        bool aleatory;
        QList<int> stimuliList;

    public:
        ProtocolSettings(int type, int basalStimulusTime, int numberOfStimuli, int stimuliTime, int timeBetweenStimuli, bool aleatory, QList<int> stimuliList);
        ~ProtocolSettings();

        int getType() const;
        void setType(int value);

        int getBasalStimulusTime() const;
        void setBasalStimulusTime(int value);

        int getNumberOfStimuli() const;
        void setNumberOfStimuli(int value);

        int getStimuliTime() const;
        void setStimuliTime(int value);

        int getTimeBetweenStimuli() const;
        void setTimeBetweenStimuli(int value);

        bool getAleatory() const;

        QList<int> getStimuliList() const;

};

#endif // PROTOCOLSETTINGS_H

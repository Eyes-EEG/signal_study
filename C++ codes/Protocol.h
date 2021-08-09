#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <QList>

#include "ProtocolSettings.h"
#include "Stimulus.h"
#include "Audio.h"
#include "Image.h"
#include "Markers.h"

class Protocol {
    private:
        QList<QSharedPointer<Stimulus>>* stimuliList;
        ProtocolSettings* settings;

    public:
        Protocol();
        ~Protocol();

        void createStimuliList(StimuliScreen* stimuliScreen, ProtocolSettings* settings);
        int getNumberOfStimuli();
        const QSharedPointer<Stimulus> getStimulus(int index);

        void addStimulus(int index, QSharedPointer<Stimulus>& stimulus);
        void addStimulus(QSharedPointer<Stimulus>& stimulus);

        void removeStimulus(int index);
        void removeStimulus(QSharedPointer<Stimulus>& stimulus);

        QList<QSharedPointer<Stimulus>>* getStimuliList() const;
        void setStimuliList(QList<QSharedPointer<Stimulus>>* value);

        ProtocolSettings* getSettings() const;
        void setSettings(ProtocolSettings* value);

    private:
        QString getPath(int marker);
        int getRandomIndex(int low, int high);
};

#endif // PROTOCOL_H

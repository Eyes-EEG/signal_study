#include "Protocol.h"

Protocol::Protocol() {
    this -> stimuliList = new QList<QSharedPointer<Stimulus>> ();
}

Protocol::~Protocol() {}

void Protocol::createStimuliList(StimuliScreen* stimuliScreen, ProtocolSettings* settings) {
    setSettings(settings);

    int basalStimuliTime = getSettings() -> getBasalStimulusTime();
    int stimuliTime = getSettings() -> getStimuliTime();
    int timeBetweenStimuli = getSettings() -> getTimeBetweenStimuli();

    int stimulusTimer = 0;
    int initStimulus = 5000;

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint> (time.msec()));

    switch(getSettings() -> getType()) {
        case (Basal): {
            break;
        }

        case (Images): {
            QSharedPointer<Stimulus> image(new Image(stimuliScreen,
                                                     Neutral,
                                                     getPath(Neutral),
                                                     initStimulus,
                                                     basalStimuliTime));
            addStimulus(image);
            stimulusTimer = initStimulus + basalStimuliTime + timeBetweenStimuli;

            int index = 0;
            int numStimuliAdded = 0;
            while(numStimuliAdded  < getSettings() -> getNumberOfStimuli()) {

                if(getSettings() -> getAleatory()) {
                    index = getRandomIndex(3, 6);
                } else {
                    index += 1;

                    if(index > 6) {
                        index = 1;
                    }
                }

                if(getSettings() -> getStimuliList().indexOf(index) != -1) {
                    QSharedPointer<Stimulus> image(new Image(stimuliScreen,
                                                             index,
                                                             getPath(index),
                                                             stimulusTimer,
                                                             stimuliTime));

                    addStimulus(image);
                    stimulusTimer += stimuliTime + timeBetweenStimuli;
                    numStimuliAdded += 1;
                }
            }

            break;
        }

        case (Audios): {
            QSharedPointer<Stimulus> image(new Image(stimuliScreen,
                                                     Neutral,
                                                     getPath(Neutral),
                                                     initStimulus,
                                                     basalStimuliTime));
            addStimulus(image);
            stimulusTimer = initStimulus + basalStimuliTime + timeBetweenStimuli;

            for(int i = 0; i < getSettings() -> getNumberOfStimuli(); i++) {
                int index = getRandomIndex(2, 2);

                QSharedPointer<Stimulus> audio(new Audio(index,
                                                         getPath(index),
                                                         stimulusTimer,
                                                         stimuliTime));

                addStimulus(audio);
                stimulusTimer += stimuliTime + timeBetweenStimuli;

            }

            break;
        }
    }
}

int Protocol::getNumberOfStimuli() {
    return getSettings() -> getNumberOfStimuli() + 1;
}

const QSharedPointer<Stimulus> Protocol::getStimulus(int index) {
    return getStimuliList() -> at(index);
}

QString Protocol::getPath(int marker) {
    switch (marker) {
        case (Neutral): {
            return *(new QString(NEUTRAL_PATH));
        }

        case (OpenCloseEyes): {
            return *(new QString(OPEN_CLOSE_EYES_PATH));
        }

        case (RightArrow): {
            return *(new QString(RIGHT_PATH));
        }

        case (LeftArrow): {
            return *(new QString(LEFT_PATH));
        }

        case (UpArrow): {
            return *(new QString(UP_PATH));
        }

        case (DownArrow): {
            return *(new QString(DOWN_PATH));
        }
    }

    return nullptr;
}

int Protocol::getRandomIndex(int low, int high) {
    return qrand() % ((high + 1) - low) + low;
}

void Protocol::addStimulus(int index, QSharedPointer<Stimulus>& stimulus) {
    getStimuliList() -> insert(index, stimulus);
}

void Protocol::addStimulus(QSharedPointer<Stimulus>& stimulus) {
    getStimuliList() -> push_back(stimulus);
}

void Protocol::removeStimulus(int index) {
    getStimuliList() -> removeAt(index);
}

void Protocol::removeStimulus(QSharedPointer<Stimulus>& stimulus) {
    getStimuliList() -> removeOne(stimulus);
}

QList<QSharedPointer<Stimulus>>* Protocol::getStimuliList() const {
    return stimuliList;
}

void Protocol::setStimuliList(QList<QSharedPointer<Stimulus>>* value) {
    stimuliList = value;
}

ProtocolSettings* Protocol::getSettings() const {
    return settings;
}

void Protocol::setSettings(ProtocolSettings* value) {
    settings = value;
}


#ifndef STIMULUSRENDERING_H
#define STIMULUSRENDERING_H

#include <QTime>
#include <QThread>

#include "StimuliScreen.h"
#include "Stimulus.h"
#include "Protocol.h"
#include "DataLogUI.h"

class StimuliRendering : public QThread {

    private:
        StimuliScreen* stimuliScreen;
        Protocol* protocol;
        DataLogUI* dataLogUI;

        QTime* timer;

        bool isPaused;
        int initTime;

    public:
        explicit StimuliRendering(DataLogUI* dataLogUI, QThread *parent = nullptr);
        ~StimuliRendering();

        void play();
        void pause();
        void restart();
        void closeStimuliScreen();

        StimuliScreen* getStimulusScreen() const;
        void setStimulusScreen(StimuliScreen* value);

        Protocol *getProtocol() const;
        void setProtocol(Protocol *value);

        QTime* getTimer() const;
        void setTimer(QTime* value);

        bool getIsPaused() const;
        void setIsPaused(bool value);

        int getInitTime() const;
        void setInitTime(int value);

        DataLogUI* getDataLogUI() const;
        void setDataLogUI(DataLogUI* value);

    protected:
        void run();

    private:
        void runStimuli();
        void clearShowed();
        bool canRun();
};

#endif // STIMULUSRENDERING_H

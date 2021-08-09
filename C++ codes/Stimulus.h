#ifndef STIMULUS_H
#define STIMULUS_H

#include <QString>
#include <QProcess>

#include "DataLogUI.h"

class Stimulus {
    private:
        int marker;
        QString path;
        bool isShowed;
        bool isStopped;
        int actionTime;
        int durationTime;


    public:
        Stimulus();
        Stimulus(int marker, QString path, int actionTime, int durationTime);
        virtual ~Stimulus();

        virtual void run(DataLogUI* dataLogUI) = 0;
        virtual void stop(DataLogUI* dataLogUI) = 0;

        void sendSignal();

        int getActionTime() const;
        void setActionTime(int value);

        int getDurationTime() const;
        void setDurationTime(int value);

        QString getPath() const;
        void setPath(QString value);

        bool getIsShowed() const;
        void setIsShowed(bool value);

        bool getIsStopped() const;
        void setIsStopped(bool value);

        int getMarker() const;
        void setMarker(int value);

    protected:
        void active(DataLogUI* dataLogUI);
        void desactive(DataLogUI* dataLogUI);
};

#endif // STIMULUS_H

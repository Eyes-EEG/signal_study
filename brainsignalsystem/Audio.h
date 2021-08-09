#ifndef AUDIO_H
#define AUDIO_H

#include <QMediaPlayer>

#include "Stimulus.h"

class Audio : public Stimulus {
    private:
        QMediaPlayer* player;

    public:
        Audio(int marker, QString path, int actionTime, int durationTime);
        ~Audio();

        void run(DataLogUI* dataLogUI);
        void stop(DataLogUI* dataLogUI);

        QMediaPlayer* getPlayer() const;
        void setPlayer(QMediaPlayer* value);
};

#endif // AUDIO_H

#include "Audio.h"

Audio::Audio(int marker, QString path, int actionTime, int durationTime) :
    Stimulus (marker, path, actionTime, durationTime){

    player = new QMediaPlayer;
    player -> setMedia(QUrl(getPath()));
    player -> setVolume(100);
}

Audio::~Audio() {}

void Audio::run (DataLogUI* dataLogUI) {
    if(!getIsShowed()) {
        getPlayer() -> play();
        active(dataLogUI);
    }
}

void Audio::stop(DataLogUI* dataLogUI) {
    if(!getIsStopped()) {
        getPlayer() -> play();
        desactive(dataLogUI);
    }
}

QMediaPlayer* Audio::getPlayer() const {
    return player;
}

void Audio::setPlayer(QMediaPlayer* value) {
    player = value;
}

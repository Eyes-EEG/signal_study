#ifndef MARKERS_H
#define MARKERS_H

static constexpr const char* OPEN_CLOSE_EYES_PATH = "qrc:sounds/pip.wav";
static constexpr const char* NEUTRAL_PATH = ":img/neutral.png";
static constexpr const char* RIGHT_PATH = ":img/right.png";
static constexpr const char* LEFT_PATH = ":img/left.png";
static constexpr const char* UP_PATH = ":img/up.png";
static constexpr const char* DOWN_PATH = ":img/down.png";

enum ProtocolTypes {
    Basal,
    Audios,
    Images
};

enum Markers {
    Neutral = 1,
    OpenCloseEyes = 2,
    RightArrow = 3,
    LeftArrow = 4,
    DownArrow = 5,
    UpArrow = 6
};

#endif // MARKERS_H

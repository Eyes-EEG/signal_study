#ifndef IMAGE_H
#define IMAGE_H

#include <QString>
#include <QMetaObject>

#include "Stimulus.h"
#include "StimuliScreen.h"

class Image : public Stimulus {
    private:
        StimuliScreen* stimuliScreen;

    public:
        Image(StimuliScreen* stimuliScreen, int marker, QString path, int actionTime, int durationTime);
        ~Image();

        void run(DataLogUI* dataLogUI);
        void stop(DataLogUI* dataLogUI);

        StimuliScreen *getStimuliScreen() const;
        void setStimuliScreen(StimuliScreen *value);
};

#endif // IMAGE_H

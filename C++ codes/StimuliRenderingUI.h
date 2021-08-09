#ifndef STIMULIRENDERINGUI_H
#define STIMULIRENDERINGUI_H

#include "StimuliRendering.h"

class StimuliRenderingUI : public QWidget {
    Q_OBJECT

    private:
        StimuliRendering* stimuliRendering;

    public:
        StimuliRenderingUI(DataLogUI* dataLogUI, QWidget* parent = nullptr);

        ~StimuliRenderingUI();

        void createScreen();

        void playStimuliRendering();
        void pauseStimuliRendering();
        void restartStimuliRendering();

        StimuliScreen* getStimuliScreen();
        void setProtocol(Protocol* protocol);

        StimuliRendering* getStimuliRendering() const;
        void setStimuliRendering(StimuliRendering* value);
};

#endif // STIMULIRENDERINGUI_H

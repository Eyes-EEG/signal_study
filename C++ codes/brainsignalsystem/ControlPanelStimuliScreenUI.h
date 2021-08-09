#ifndef CONTROLPANELSTIMULISCREENUI_H
#define CONTROLPANELSTIMULISCREENUI_H

#include <QWidget>
#include <QHBoxLayout>
#include <QToolButton>
#include <QStyle>
#include <QString>
#include <QList>

#include "ProtocolsUI.h"
#include "Protocol.h"
#include "StimuliRenderingUI.h"

const QSize ICONSIZE(36, 36);

class ControlPanelStimuliScreenUI : public QHBoxLayout {
    Q_OBJECT

    private:
        StimuliRenderingUI* stimuliRenderingUI;

        ProtocolsUI* protocolsUI;
        DataLogUI* dataLogUI;

        QToolButton* stimuliScreenButton;
        QToolButton* playButton;
        QToolButton* pauseButton;
        QToolButton* restartButton;
        QToolButton* stopButton;
        QToolButton* saveButton;

    public:
        ControlPanelStimuliScreenUI(ProtocolsUI* protocolsUI, DataLogUI* dataLog);
        ~ControlPanelStimuliScreenUI();

        void closeScreen();

        StimuliRenderingUI* getStimuliRenderingUI() const;
        void setStimuliRenderingUI(StimuliRenderingUI* value);

        ProtocolsUI* getProtocolsUI() const;
        void setProtocolsUI(ProtocolsUI* value);

        QToolButton* getStimuliScreenButton() const;
        void setStimuliScreenButton(QToolButton* value);

        QToolButton* getPlayButton() const;
        void setPlayButton(QToolButton* value);

        QToolButton* getPauseButton() const;
        void setPauseButton(QToolButton* value);

        QToolButton* getRestartButton() const;
        void setRestartButton(QToolButton* value);

        QToolButton* getStopButton() const;
        void setStopButton(QToolButton* value);

        QToolButton* getSaveButton() const;
        void setSaveButton(QToolButton* value);

        DataLogUI* getDataLogUI() const;
        void setDataLogUI(DataLogUI* value);

    private:
        void createContent();
        QToolButton* createButton(QString name, QStyle::StandardPixmap icon);
        void createStimuliButtonScreen();
        void createPlayButton();
        void createPauseButton();
        void createRestartButton();
        void createStopButton();
        void createSaveButton();

    private slots:
        void createStimuliRendering();
        void playStimuliRendering();
        void pauseStimuliRendering();
        void restartStimuliRendering();
        void stopStimuliRendering();

};

#endif // CONTROLPANELSTIMULISCREENUI_H

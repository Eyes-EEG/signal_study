#ifndef PROTOCOLSUI_H
#define PROTOCOLSUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTabWidget>

#include "BasalProtocolUI.h"
#include "ImageProtocolUI.h"
#include "AudioProtocolUI.h"

class ProtocolsUI : public QWidget {
    Q_OBJECT

    private:
        ProtocolUI* basalProtocolUI;
        ProtocolUI* imageProtocolUI;
        ProtocolUI* audioProtocolUI;

        QTabWidget* tabProtocols;

    public:
        explicit ProtocolsUI(QWidget *parent = nullptr);
        ~ProtocolsUI();

        int getProtocolSelected();
        int getBasalStimulusTime();
        int getNumberStimuliSelected();
        int getStimuliTimeSelected();
        int getTimeBetweenStimuliSelected();

        QTabWidget* getTabProtocols() const;
        void setTabProtocols(QTabWidget* value);

        ProtocolUI* getBasalProtocolUI() const;
        void setBasalProtocolUI(ProtocolUI* value);

        ProtocolUI* getImageProtocolUI() const;
        void setImageProtocolUI(ProtocolUI* value);

        ProtocolUI* getAudioProtocolUI() const;
        void setAudioProtocolUI(ProtocolUI* value);

    private:
        void createTabProtocols();
        ProtocolUI* getSelectedProtocolUI();
        StimuliProtocolUI* getSelectedStimuliProtocolUI();
};

#endif // PROTOCOLSUI_H

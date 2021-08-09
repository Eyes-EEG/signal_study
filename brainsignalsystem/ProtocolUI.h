#ifndef PROTOCOLUI_H
#define PROTOCOLUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>

class ProtocolUI : public QVBoxLayout {

    private:
        QSpinBox* basalStimulusTime;

    public:
        ProtocolUI();
        ~ProtocolUI();

        int getBasalStimulusTimeSelected();

        QSpinBox* getBasalStimulusTime() const;
        void setBasalStimulusTime(QSpinBox* value);

    private:
        void createBasalStimulusTimeInput();

};

#endif // PROTOCOLUI_H

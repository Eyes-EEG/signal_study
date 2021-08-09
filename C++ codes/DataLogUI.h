#ifndef DATALOGUI_H
#define DATALOGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QTime>

#include <Markers.h>

class DataLogUI : public QWidget {
    Q_OBJECT

    private:
        QVBoxLayout* eventLogs;

    public:
        DataLogUI(QWidget* parent = nullptr);
        ~DataLogUI();

        void showText(QString* text);

        QVBoxLayout* getEventLogs() const;
        void setEventLogs(QVBoxLayout* value);

    public slots:
        void addStimulusLog(int stimulusIndex, bool state);

    private:
        QString* getStimulusName(int marker);
};

#endif // DATALOGUI_H

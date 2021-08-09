#ifndef STIMULUSSCREEN_H
#define STIMULUSSCREEN_H

#include <QtCore>
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

class StimuliScreen : public QWidget {
    Q_OBJECT

    private:
        QHBoxLayout* layout;
        QLabel* image;
        QPixmap* pixmap;

    public:
        explicit StimuliScreen(QWidget *parent = nullptr);
        ~StimuliScreen();

        void clear();

    public slots:
        void updateImage(QString path);

};

#endif // STIMULUSSCREEN_H

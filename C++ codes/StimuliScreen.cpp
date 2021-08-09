#include "StimuliScreen.h"

StimuliScreen::StimuliScreen(QWidget *parent) : QWidget(parent) {
    image = new QLabel(this);
    layout = new QHBoxLayout();

    image = new QLabel(this);
    image -> setAlignment(Qt::AlignCenter);

    layout = new QHBoxLayout();
    layout -> addWidget(image);

    setLayout(layout);
}

StimuliScreen::~StimuliScreen() {}

void StimuliScreen::updateImage(QString path) {
    char* str = (char*) malloc(10);
    QByteArray ba = path.toLatin1();
    strcpy(str, ba.data());

    image -> setPixmap(QPixmap(str));
    layout -> removeWidget(image);
    layout -> addWidget(image);

    repaint();
}

void StimuliScreen::clear() {
    image -> clear();
}

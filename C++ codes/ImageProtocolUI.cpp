#include "ImageProtocolUI.h"

ImageProtocolUI::ImageProtocolUI() {
    aleatory = new QCheckBox("Aleatory");
    addWidget(aleatory);

    right = new QCheckBox("Right");
    addWidget(right);
    left = new QCheckBox("Left");
    addWidget(left);
    down = new QCheckBox("Down");
    addWidget(down);
    up = new QCheckBox("Up");
    addWidget(up);
}

ImageProtocolUI::~ImageProtocolUI() {}

QCheckBox* ImageProtocolUI::getAleatory() const {
    return aleatory;
}

QCheckBox* ImageProtocolUI::getUp() const {
    return up;
}

QCheckBox* ImageProtocolUI::getDown() const {
    return down;
}

QCheckBox* ImageProtocolUI::getRight() const {
    return right;
}

QCheckBox* ImageProtocolUI::getLeft() const {
    return left;
}

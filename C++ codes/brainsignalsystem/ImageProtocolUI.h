#ifndef IMAGEPROTOCOLUI_H
#define IMAGEPROTOCOLUI_H

#include <QCheckBox>

#include "StimuliProtocolUI.h"

class ImageProtocolUI : public StimuliProtocolUI {
    private:
        QCheckBox* aleatory;

        QCheckBox* up;
        QCheckBox* down;
        QCheckBox* right;
        QCheckBox* left;

    public:
        explicit ImageProtocolUI();
        ~ImageProtocolUI();

        QCheckBox* getAleatory() const;
        QCheckBox* getUp() const;
        QCheckBox* getDown() const;
        QCheckBox* getRight() const;
        QCheckBox* getLeft() const;
};

#endif // IMAGEPROTOCOLUI_H

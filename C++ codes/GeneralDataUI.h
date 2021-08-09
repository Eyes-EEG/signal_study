#ifndef GENERALDATAUI_H
#define GENERALDATAUI_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QTextEdit>

class GeneralDataUI : public QWidget {

    public:
        explicit GeneralDataUI(QWidget *parent = nullptr);
        ~GeneralDataUI();
};

#endif // GENERALDATAUI_H

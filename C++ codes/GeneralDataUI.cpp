#include "GeneralDataUI.h"

GeneralDataUI::GeneralDataUI(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout();

    QHBoxLayout* layout = new QHBoxLayout();
    QLabel* pacientTitle = new QLabel("Patient: ");
    QLineEdit* pacientText = new QLineEdit();
    QLabel* date = new QLabel("Date: ");
    QLineEdit* dateText = new QLineEdit();

    layout -> addWidget(pacientTitle);
    layout -> addWidget(pacientText);
    layout -> addWidget(date);
    layout -> addWidget(dateText);
    mainLayout -> addLayout(layout);

    layout = new QHBoxLayout();
    QLabel* commentsTitle = new QLabel("Comments: ");
    layout -> addWidget(commentsTitle);
    mainLayout -> addLayout(layout);

    layout = new QHBoxLayout();
    QTextEdit* commentsText = new QTextEdit();
    layout -> addWidget(commentsText);
    mainLayout -> addLayout(layout);

    setLayout(mainLayout);
}

GeneralDataUI::~GeneralDataUI() {

}

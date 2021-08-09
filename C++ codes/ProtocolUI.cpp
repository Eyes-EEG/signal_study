#include "ProtocolUI.h"

ProtocolUI::ProtocolUI()  {
    QHBoxLayout* layout = new QHBoxLayout();
    QLabel* protocolTitle = new QLabel("Basal stimulus time (sec):");

    basalStimulusTime = new QSpinBox();

    createBasalStimulusTimeInput();

    layout -> addWidget(protocolTitle);
    layout -> addWidget(basalStimulusTime);

    addLayout(layout);
}

ProtocolUI::~ProtocolUI() {}

void ProtocolUI::createBasalStimulusTimeInput() {
    getBasalStimulusTime() -> setRange(0, 20);
    getBasalStimulusTime() -> setSingleStep(1);
    getBasalStimulusTime() -> setValue(0);
}

int ProtocolUI::getBasalStimulusTimeSelected() {
    return getBasalStimulusTime() -> value();
}

QSpinBox* ProtocolUI::getBasalStimulusTime() const {
    return basalStimulusTime;
}

void ProtocolUI::setBasalStimulusTime(QSpinBox* value) {
    basalStimulusTime = value;
}

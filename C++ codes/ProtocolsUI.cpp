#include "ProtocolsUI.h"

#include <QDebug>

ProtocolsUI::ProtocolsUI(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout();

    QHBoxLayout* layout = new QHBoxLayout();
    QLabel* protocolTitle = new QLabel("Protocols");
    layout -> addWidget(protocolTitle);
    mainLayout -> addLayout(layout);

    tabProtocols = new QTabWidget;
    createTabProtocols();

    mainLayout -> addWidget(tabProtocols);

    setLayout(mainLayout);
}

ProtocolsUI::~ProtocolsUI() {}

void ProtocolsUI::createTabProtocols() {
    QWidget* protocol = nullptr;

    protocol = new QWidget();
    setBasalProtocolUI(new BasalProtocolUI());
    protocol -> setLayout(getBasalProtocolUI());
    getTabProtocols() -> addTab(protocol, tr("Basal"));

    protocol = new QWidget();
    setAudioProtocolUI(new AudioProtocolUI());
    protocol -> setLayout(getAudioProtocolUI());
    getTabProtocols() -> addTab(protocol, tr("Audios"));

    protocol = new QWidget();
    setImageProtocolUI(new ImageProtocolUI());
    protocol -> setLayout(getImageProtocolUI());
    getTabProtocols() -> addTab(protocol, tr("Images"));
}

int ProtocolsUI::getProtocolSelected() {
    return getTabProtocols() -> currentIndex();
}

int ProtocolsUI::getBasalStimulusTime() {
    return getSelectedProtocolUI() -> getBasalStimulusTimeSelected();
}

int ProtocolsUI::getNumberStimuliSelected() {
    StimuliProtocolUI* protocolUI = getSelectedStimuliProtocolUI();

    if(protocolUI != nullptr) {
        return protocolUI -> getNumberStimuliSelected();
    }

    return -1;
}

int ProtocolsUI::getStimuliTimeSelected() {
    StimuliProtocolUI* protocolUI = getSelectedStimuliProtocolUI();

    if(protocolUI != nullptr) {
        return protocolUI -> getStimuliTimeSelected();
    }

    return -1;
}

int ProtocolsUI::getTimeBetweenStimuliSelected() {
    StimuliProtocolUI* protocolUI = getSelectedStimuliProtocolUI();

    if(protocolUI != nullptr) {
        return protocolUI -> getTimeBetweenStimuliSelected();
    }

    return -1;
}

ProtocolUI* ProtocolsUI::getSelectedProtocolUI() {
    switch (getProtocolSelected()) {
        case (0): {
            return dynamic_cast<ProtocolUI*> (getAudioProtocolUI());
        }

        case (1): {
            return dynamic_cast<ProtocolUI*> (getAudioProtocolUI());
        }

        case (2): {
            return dynamic_cast<ProtocolUI*> (getImageProtocolUI());
        }
    }

    return nullptr;
}

StimuliProtocolUI* ProtocolsUI::getSelectedStimuliProtocolUI() {
    switch (getProtocolSelected()) {
        case (1): {
            return dynamic_cast<StimuliProtocolUI*> (getAudioProtocolUI());
        }

        case (2): {
            return dynamic_cast<StimuliProtocolUI*> (getImageProtocolUI());
        }
    }

    return nullptr;
}

QTabWidget* ProtocolsUI::getTabProtocols() const {
    return tabProtocols;
}

void ProtocolsUI::setTabProtocols(QTabWidget* value) {
    tabProtocols = value;
}

ProtocolUI* ProtocolsUI::getBasalProtocolUI() const {
    return basalProtocolUI;
}

void ProtocolsUI::setBasalProtocolUI(ProtocolUI* value) {
    basalProtocolUI = value;
}

ProtocolUI* ProtocolsUI::getImageProtocolUI() const {
    return imageProtocolUI;
}

void ProtocolsUI::setImageProtocolUI(ProtocolUI* value) {
    imageProtocolUI = value;
}

ProtocolUI* ProtocolsUI::getAudioProtocolUI() const {
    return audioProtocolUI;
}

void ProtocolsUI::setAudioProtocolUI(ProtocolUI* value) {
    audioProtocolUI = value;
}

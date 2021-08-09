#include "StimuliRenderingUI.h"

StimuliRenderingUI::StimuliRenderingUI(DataLogUI* dataLogUI, QWidget *parent) : QWidget(parent) {
    stimuliRendering = new StimuliRendering(dataLogUI);

    setStyleSheet("background-color: black;");
    createScreen();

    getStimuliRendering() -> start();
}

StimuliRenderingUI::~StimuliRenderingUI() {}

void StimuliRenderingUI::createScreen() {
    QVBoxLayout* contentBox = new QVBoxLayout();
    contentBox -> addWidget(getStimuliRendering() -> getStimulusScreen());
    setLayout(contentBox);
}

void StimuliRenderingUI::playStimuliRendering() {
    getStimuliRendering() -> play();
}

void StimuliRenderingUI::pauseStimuliRendering() {
    getStimuliRendering() -> pause();
}

void StimuliRenderingUI::restartStimuliRendering() {
    getStimuliRendering() -> restart();
}

StimuliScreen* StimuliRenderingUI::getStimuliScreen() {
    return getStimuliRendering() -> getStimulusScreen();
}

void StimuliRenderingUI::setProtocol(Protocol* protocol) {
    getStimuliRendering() -> setProtocol(protocol);
}

StimuliRendering* StimuliRenderingUI::getStimuliRendering() const {
    return stimuliRendering;
}

void StimuliRenderingUI::setStimuliRendering(StimuliRendering* value) {
    stimuliRendering = value;
}

#include "ControlPanelStimuliScreenUI.h"

ControlPanelStimuliScreenUI::ControlPanelStimuliScreenUI(ProtocolsUI* protocolsUI, DataLogUI* dataLogUI) {
    createContent();

    stimuliRenderingUI = nullptr;
    this -> protocolsUI = protocolsUI;
    this -> dataLogUI = dataLogUI;
}

ControlPanelStimuliScreenUI::~ControlPanelStimuliScreenUI() {}

void ControlPanelStimuliScreenUI::createContent() {
    createStimuliButtonScreen();
    createPlayButton();
    createPauseButton();
    createStopButton();
    createRestartButton();
    createSaveButton();
}

void ControlPanelStimuliScreenUI::createStimuliButtonScreen() {
    setStimuliScreenButton(createButton(*(new QString("Create stimuli screen")), QStyle::SP_DialogYesButton));
    connect(getStimuliScreenButton(), SIGNAL (clicked()), this, SLOT(createStimuliRendering()));

    addWidget(getStimuliScreenButton());
}

void ControlPanelStimuliScreenUI::createPlayButton() {
    setPlayButton(createButton(*(new QString("Play")), QStyle::SP_MediaPlay));
    connect(getPlayButton(), SIGNAL (clicked()), this, SLOT(playStimuliRendering()));
    getPlayButton() -> setDisabled(true);

    addWidget(getPlayButton());
}

void ControlPanelStimuliScreenUI::createPauseButton() {
    setPauseButton(createButton(*(new QString("Pause")), QStyle::SP_MediaPause));
    connect(getPauseButton(), SIGNAL (clicked()), this, SLOT(pauseStimuliRendering()));
    getPauseButton() -> setDisabled(true);

    addWidget(getPauseButton());
}

void ControlPanelStimuliScreenUI::createRestartButton() {
    setRestartButton(createButton(*(new QString("Restart")), QStyle::SP_BrowserReload));
    connect(getRestartButton(), SIGNAL (clicked()), this, SLOT(restartStimuliRendering()));
    getRestartButton() -> setDisabled(true);

    addWidget(getRestartButton());
}

void ControlPanelStimuliScreenUI::createStopButton() {
    setStopButton(createButton(*(new QString("Stop")), QStyle::SP_MediaStop));
    connect(getStopButton(), SIGNAL (clicked()), this, SLOT(stopStimuliRendering()));
    getStopButton() -> setDisabled(true);

    addWidget(getStopButton());
}

void ControlPanelStimuliScreenUI::createSaveButton() {
    setSaveButton(createButton(*(new QString("Save")), QStyle::SP_DialogSaveButton));

    addWidget(getSaveButton());
}

QToolButton* ControlPanelStimuliScreenUI::createButton(QString name, QStyle::StandardPixmap icon) {
    QWidget* parent = new QWidget();
    QToolButton* button = new QToolButton();
    button -> setIcon(parent -> style() -> standardIcon(icon));
    button -> setIconSize(ICONSIZE);

    QByteArray ba = name.toLatin1();
    const char* c_str2 = ba.data();

    button -> setToolTip(tr(c_str2));
    button -> setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    return button;
}

void ControlPanelStimuliScreenUI::createStimuliRendering() {

    Protocol* protocol = new Protocol();

    QList<int> stimuliList;

    bool aleatory = false;

    if (getProtocolsUI() -> getProtocolSelected() == Images) {
        ImageProtocolUI* imageProtocol = dynamic_cast<ImageProtocolUI*>(getProtocolsUI() -> getImageProtocolUI());

        if(imageProtocol -> getAleatory() -> isChecked())
            aleatory = true;

        if(imageProtocol -> getUp() -> isChecked()) {
            stimuliList.append(UpArrow);
        }

        if(imageProtocol -> getDown() -> isChecked()) {
            stimuliList.append(DownArrow);
        }

        if(imageProtocol -> getRight() -> isChecked()) {
            stimuliList.append(RightArrow);
        }

        if(imageProtocol -> getLeft() -> isChecked()) {
            stimuliList.append(LeftArrow);
        }
    }

    ProtocolSettings* settings =
            new ProtocolSettings(getProtocolsUI() -> getProtocolSelected(),
                                 getProtocolsUI() -> getBasalStimulusTime() * 1000,
                                 getProtocolsUI() -> getNumberStimuliSelected(),
                                 getProtocolsUI() -> getStimuliTimeSelected() * 1000,
                                 getProtocolsUI() -> getTimeBetweenStimuliSelected() * 1000,
                                 aleatory,
                                 stimuliList);

    setStimuliRenderingUI(new StimuliRenderingUI(getDataLogUI()));
    protocol -> createStimuliList(getStimuliRenderingUI() -> getStimuliScreen(),
                                  settings);

    getStimuliRenderingUI() -> setProtocol(protocol);
    getStimuliRenderingUI() -> show();

    getStimuliScreenButton() -> setDisabled(true);
    getPlayButton() -> setDisabled(false);
    getPauseButton() -> setDisabled(false);
    getStopButton() -> setDisabled(false);
    getRestartButton() -> setDisabled(false);
}

void ControlPanelStimuliScreenUI::playStimuliRendering() {
    getStimuliRenderingUI() -> playStimuliRendering();
}

void ControlPanelStimuliScreenUI::pauseStimuliRendering() {
    getStimuliRenderingUI() -> pauseStimuliRendering();
}

void ControlPanelStimuliScreenUI::restartStimuliRendering() {
    getStimuliRenderingUI() -> restartStimuliRendering();
}

void ControlPanelStimuliScreenUI::stopStimuliRendering() {
    closeScreen();

    getStimuliScreenButton() -> setDisabled(false);
    getPlayButton() -> setDisabled(true);
    getPauseButton() -> setDisabled(true);
    getStopButton() -> setDisabled(true);
    getRestartButton() -> setDisabled(true);
}

void ControlPanelStimuliScreenUI::closeScreen() {
    if(getStimuliRenderingUI() != nullptr) {
        getStimuliRenderingUI() -> getStimuliRendering() -> closeStimuliScreen();
        getStimuliRenderingUI() -> close();
    }
}

ProtocolsUI* ControlPanelStimuliScreenUI::getProtocolsUI() const {
    return protocolsUI;
}

void ControlPanelStimuliScreenUI::setProtocolsUI(ProtocolsUI* value) {
    protocolsUI = value;
}

StimuliRenderingUI* ControlPanelStimuliScreenUI::getStimuliRenderingUI() const {
    return stimuliRenderingUI;
}

void ControlPanelStimuliScreenUI::setStimuliRenderingUI(StimuliRenderingUI* value) {
    stimuliRenderingUI = value;
}

QToolButton* ControlPanelStimuliScreenUI::getStimuliScreenButton() const {
    return stimuliScreenButton;
}

void ControlPanelStimuliScreenUI::setStimuliScreenButton(QToolButton* value) {
    stimuliScreenButton = value;
}

QToolButton* ControlPanelStimuliScreenUI::getPlayButton() const {
    return playButton;
}

void ControlPanelStimuliScreenUI::setPlayButton(QToolButton* value) {
    playButton = value;
}

QToolButton *ControlPanelStimuliScreenUI::getPauseButton() const {
    return pauseButton;
}

void ControlPanelStimuliScreenUI::setPauseButton(QToolButton *value) {
    pauseButton = value;
}

QToolButton *ControlPanelStimuliScreenUI::getRestartButton() const {
    return restartButton;
}

void ControlPanelStimuliScreenUI::setRestartButton(QToolButton *value) {
    restartButton = value;
}

QToolButton *ControlPanelStimuliScreenUI::getStopButton() const {
    return stopButton;
}

void ControlPanelStimuliScreenUI::setStopButton(QToolButton *value) {
    stopButton = value;
}

QToolButton *ControlPanelStimuliScreenUI::getSaveButton() const {
    return saveButton;
}

void ControlPanelStimuliScreenUI::setSaveButton(QToolButton *value) {
    saveButton = value;
}

DataLogUI* ControlPanelStimuliScreenUI::getDataLogUI() const {
    return dataLogUI;
}

void ControlPanelStimuliScreenUI::setDataLogUI(DataLogUI* value) {
    dataLogUI = value;
}

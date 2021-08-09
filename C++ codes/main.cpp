#include <QApplication>

#include "StimuliMenuUI.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    StimuliMenuUI window;

    window.show();

    return app.exec();
}

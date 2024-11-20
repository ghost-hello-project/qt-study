#include <QApplication>

#include "qt-hello/app/mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow   w;
    w.show();
    return QApplication::exec();
}

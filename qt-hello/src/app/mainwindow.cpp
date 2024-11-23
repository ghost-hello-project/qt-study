#include "qt-hello/app/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    this->log = janna::LogUtil::getLogger("app");
}

void MainWindow::closeEvent(QCloseEvent *event) {
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna is closing..."));
    // 如果你想阻止窗口关闭，取消事件
    // event->ignore();

    event->accept();
}
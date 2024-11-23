#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <spdlog/spdlog.h>

#include <QCloseEvent>
#include <QMainWindow>

#include "qt-hello/util/log_util.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    std::shared_ptr<spdlog::logger> log;
};
#endif  // MAINWINDOW_H

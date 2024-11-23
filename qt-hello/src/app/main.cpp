#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>

#include <QApplication>
#include <QSysInfo>
#include <cstdlib>

#include "qt-hello/app/mainwindow.h"
#include "qt-hello/util/app_config.h"
#include "qt-hello/util/log_util.h"

void exit();

using namespace janna;
int main(int argc, char *argv[]) {
    LogUtil::init(AppConfig::getInstance()->logLevel(), "../logs/app.log");
    std::shared_ptr<spdlog::logger> log = LogUtil::getLogger("app");
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna is running..."));

    QApplication a(argc, argv);
    MainWindow   w;
    w.show();

    auto result = QApplication::exec();
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna result code:{}", result));
    log->flush();
    spdlog::shutdown();
    exit();
    return result;
}

void exit() {
#ifdef Q_OS_WIN
    std::string exit_cmd = "taskkill /t /f /PID " + std::to_string(_getpid());
    system(exit_cmd.c_str());
#endif
}
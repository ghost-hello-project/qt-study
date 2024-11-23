#include <spdlog/fmt/fmt.h>
#include <spdlog/spdlog.h>

#include <QApplication>

#include "qt-hello/app/mainwindow.h"
#include "qt-hello/util/app_config.h"
#include "qt-hello/util/log_util.h"

int main(int argc, char *argv[]) {
    janna::LogUtil::init(janna::AppConfig::getInstance()->logLevel(), "../logs/app.log");
    std::shared_ptr<spdlog::logger> log = janna::LogUtil::getLogger("app");
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna is running..."));

    QApplication a(argc, argv);
    MainWindow   w;
    w.show();

    auto result = QApplication::exec();
    SPDLOG_LOGGER_DEBUG(log, fmt::format("janna result code:{}", result));
    log->flush();
    spdlog::shutdown();
    return result;
}

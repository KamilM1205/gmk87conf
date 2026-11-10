#include "launcher.hpp"
#include "ui/fonts_resources.hpp"
#include "ui/mainwindow.hpp"
#include <QFile>
#include <QtCore/qcoreapplication.h>
#include <QtCore/qlogging.h>
#include <QtGui/qevent.h>
#include <cstdlib>

Launcher::Launcher(std::int32_t argc, char **argv) {
  app = std::make_unique<QApplication>(argc, argv);
  UI::Fonts::RegistrateFonts();

  loadStyle();
}

void Launcher::loadStyle() {
  QFile style_file(":/styles/styles.qss");
  if (style_file.open(QFile::ReadOnly | QFile::Text)) {
    app->setStyleSheet(QString::fromUtf8(style_file.readAll()));
  } else {
    qWarning() << "Cannot load style file";
  }
}

auto Launcher::run() -> std::int32_t {
  MainWindow window;
  window.show();

  return app->exec();
}

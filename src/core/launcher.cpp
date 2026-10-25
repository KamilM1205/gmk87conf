#include "launcher.hpp"
#include "ui/mainwindow.hpp"
#include <cstdlib>

Launcher::Launcher(std::int32_t argc, char **argv) {
  app = std::make_unique<QApplication>(argc, argv);
}

auto Launcher::run() -> std::int32_t {
  		MainWindow window;
  		window.show();

  return app->exec();
}

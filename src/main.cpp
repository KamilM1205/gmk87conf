#include "core/launcher.hpp"
#include "utils/qrc_output.hpp"
#include <QtCore/qlogging.h>
#include <QtCore/qtresource.h>
#include <iostream>

int main(int argc, char *argv[]) {
  Q_INIT_RESOURCE(resources);

  Launcher launcher(argc, argv);

  std::cout << Utils::getFormattedListOfAllQRC();

  return launcher.run();
}

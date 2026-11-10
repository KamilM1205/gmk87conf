#include <QApplication>
#include <QtCore/qtresource.h>
#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
  Q_INIT_RESOURCE(resources);
  QApplication app(argc, argv);

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

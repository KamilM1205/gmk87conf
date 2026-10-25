#include "mainwindow.hpp"
#include <QtWidgets/qwidget.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowTitle("GMK87Configurator");
  setMinimumSize(800, 600);
}

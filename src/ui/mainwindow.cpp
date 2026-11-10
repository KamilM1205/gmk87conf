#include "mainwindow.hpp"
#include "ui/widgets/titlebar.hpp"
#include <QtCore/qnamespace.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qwidget.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
  setMinimumSize(800, 600);

  auto *central = new QWidget(this);
  central->setContentsMargins(0, 0, 0, 0);

  auto *layout = new QVBoxLayout(central);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setAlignment(Qt::AlignTop);

  setupTitleBar();

  layout->addWidget(m_titlebar);

  setCentralWidget(central);
}

void MainWindow::setupTitleBar() {
  m_titlebar = new TitleBar(this);

  connect(m_titlebar, &TitleBar::minimizeRequested, this,
          &QWidget::showMinimized);
  connect(m_titlebar, &TitleBar::maximizeRequested, this, [this] {
    if (isMaximized()) {
      showNormal();
    } else {
      showMaximized();
    }
  });
  connect(m_titlebar, &TitleBar::closeRequested, this, &QWidget::close);
  connect(m_titlebar, &TitleBar::moveRequested, this,
          [this](auto pos) { move(pos.x(), pos.y()); });
}

#include "rounded_window.hpp"
#include <QDebug>
#include <QStyleOption>
#include <QtCore/qnamespace.h>
#include <QtCore/qtpreprocessorsupport.h>
#include <QtGui/qbrush.h>
#include <QtGui/qcolor.h>
#include <QtGui/qevent.h>
#include <QtGui/qpainter.h>

namespace UI {
RoundedWindow::RoundedWindow(QWidget *parent) : QMainWindow(parent) {
  setWindowFlags(Qt::FramelessWindowHint | Qt::Window);
  setAttribute(Qt::WA_TranslucentBackground);
  setContentsMargins(10, 10, 10, 10);

  setStyleSheet(R"(
        UI--RoundedWindow {
            border-radius: 16px;
        }
    )");
}

void RoundedWindow::paintEvent(QPaintEvent *event) {
  QStyleOption opt;
  opt.initFrom(this);
  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

  QWidget::paintEvent(event);
}

} // namespace UI

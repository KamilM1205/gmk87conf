#include "titlebar.hpp"
#include "ui/icon_resources.hpp"
#include "ui/widgets/buttons/icon_button.hpp"
#include <QtCore/qdebug.h>
#include <QtCore/qlogging.h>
#include <QtCore/qnamespace.h>
#include <QtCore/qtmetamacros.h>
#include <QtEvents>
#include <QtGui/qevent.h>
#include <QtGui/qwindowdefs.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>

TitleBar::TitleBar(QWidget *parent) : QWidget(parent) {
#if __APPLE__
  m_is_left_hand = true;
#else
  m_is_left_hand = false;
#endif

  setFixedHeight(45);

  loadIcons();
  initWidgets();

  auto *layout = new QHBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->setSpacing(0);

  if (!m_is_left_hand) {
    layout->addWidget(m_title);
    layout->addStretch();

    layout->addWidget(m_minimizeBtn);
    layout->addWidget(m_maximizeBtn);
    layout->addWidget(m_closeBtn);
  } else {
    layout->addWidget(m_closeBtn);
    layout->addWidget(m_minimizeBtn);
    layout->addWidget(m_maximizeBtn);

    layout->addStretch();
    layout->addWidget(m_title);
  }

  connect(m_minimizeBtn, &QPushButton::clicked, this,
          &TitleBar::minimizeRequested);
  connect(m_maximizeBtn, &QPushButton::clicked, this,
          &TitleBar::maximizeRequested);
  connect(m_closeBtn, &QPushButton::clicked, this, &TitleBar::closeRequested);
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    emit maximizeRequested();
  }

  QWidget::mouseDoubleClickEvent(event);
}

void TitleBar::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    m_start_position = event->globalPosition().toPoint() -
                       QWidget::window()->frameGeometry().topLeft();
    is_drag = true;
  } else {
    is_drag = false;
    QWidget::mousePressEvent(event);
  }
}

void TitleBar::mouseMoveEvent(QMouseEvent *event) {
  if (!(event->buttons() & Qt::LeftButton) && !is_drag) {
    return;
  }

  if ((event->globalPosition().toPoint() - m_start_position)
          .manhattanLength() >= QApplication::startDragDistance()) {
    const auto delta = event->globalPosition().toPoint() - m_start_position;
    emit moveRequested(delta);
  }

  QWidget::mouseMoveEvent(event);
}

bool TitleBar::eventFilter(QObject *obj, QEvent *event) { return false; }

void TitleBar::loadIcons() {
  const QString baseColor("#e3e3e3");
  const QString newColor("#f5f5f5");
  const QString newColorHover("#080808");
  const QSize iconSize(45, 45);
}

void TitleBar::initWidgets() {
  m_title = new QLabel("GMK87Configurator");
  m_title->setObjectName("titlebarTitle");

  m_minimizeBtn = new UI::IconButton(this);
  m_minimizeBtn->setFixedSize(45, 42);
  m_minimizeBtn->setIcon(UI::Icons::MinimizeIcon);
  m_minimizeBtn->setContentsMargins(0, 3, 0, 0);
  m_minimizeBtn->setObjectName("titlebarMinimizeBtn");
  m_minimizeBtn->installEventFilter(this);

  m_maximizeBtn = new UI::IconButton(this);
  m_maximizeBtn->setFixedSize(45, 42);
  m_maximizeBtn->setIcon(UI::Icons::MaximizeIcon);
  m_maximizeBtn->setContentsMargins(0, 3, 0, 0);
  m_maximizeBtn->setObjectName("titlebarMaximizeBtn");
  m_maximizeBtn->installEventFilter(this);

  m_closeBtn = new UI::IconButton(this);
  m_closeBtn->setFixedSize(45, 42);
  m_closeBtn->setIcon(UI::Icons::CloseIcon);
  m_closeBtn->setContentsMargins(0, 3, 0, 0);
  m_closeBtn->setObjectName("titlebarCloseBtn");
  m_closeBtn->installEventFilter(this);
}

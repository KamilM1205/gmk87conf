#include "icon_button.hpp"
#include "ui/icon_resources.hpp"
#include "ui/utils/colored_icon.hpp"
#include "ui/widgets/titlebar.hpp"
#include <QtCore/qhashfunctions.h>
#include <QtCore/qsize.h>
#include <QtGui/qcolor.h>
#include <QtGui/qevent.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>

namespace UI {

IconButton::IconButton(QWidget *parent) : QPushButton(parent) {
  m_normal_icon_color = QColorConstants::LightGray;
  m_hovered_icon_color = QColorConstants::Gray;
  m_clicked_icon_color = QColorConstants::DarkGray;

  m_normal_icon = ColoredIcon::DefaultIcon();
  m_hovered_icon = ColoredIcon::DefaultIcon();
  m_clicked_icon = ColoredIcon::DefaultIcon();

  m_icon_size = QSize(45, 45);
  m_path = Icons::DefaultIcon;

  QPushButton::setIcon(m_normal_icon);
}

void IconButton::setIcon(const QString &path) {
  m_path = path;

  m_normal_icon =
      ColoredIcon::CreateIcon(path, m_normal_icon_color.name(), m_icon_size);
  m_hovered_icon =
      ColoredIcon::CreateIcon(path, m_hovered_icon_color.name(), m_icon_size);
  m_clicked_icon =
      ColoredIcon::CreateIcon(path, m_clicked_icon_color.name(), m_icon_size);

  QPushButton::setIcon(m_normal_icon);
}

auto IconButton::iconColor() const -> const QColor {
  return m_normal_icon_color;
}

auto IconButton::iconColorHover() const -> const QColor {
  return m_hovered_icon_color;
}

auto IconButton::iconColorClicked() const -> const QColor {
  return m_clicked_icon_color;
}

void IconButton::setIconColor(QColor color) {
  m_normal_icon_color = color;
  m_normal_icon =
      ColoredIcon::CreateIcon(m_path, m_normal_icon_color.name(), m_icon_size);
}

void IconButton::setIconColorHover(QColor color) {
  m_hovered_icon_color = color;
  m_hovered_icon =
      ColoredIcon::CreateIcon(m_path, m_hovered_icon_color.name(), m_icon_size);
}

void IconButton::setIconColorClicked(QColor color) {
  m_clicked_icon_color = color;
  m_clicked_icon =
      ColoredIcon::CreateIcon(m_path, m_clicked_icon_color.name(), m_icon_size);
}

void IconButton::enterEvent(QEnterEvent *event) {
  QPushButton::setIcon(m_hovered_icon);

  QPushButton::enterEvent(event);
}

void IconButton::leaveEvent(QEvent *event) {
  QPushButton::setIcon(m_normal_icon);

  QPushButton::leaveEvent(event);
}

} // namespace UI

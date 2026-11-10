#ifndef WIDGET_TITLEBAR_HPP
#define WIDGET_TITLEBAR_HPP

#include "ui/widgets/buttons/icon_button.hpp"
#include <QtCore/qpoint.h>
#include <QtCore/qtmetamacros.h>
#include <QtWidgets/qwidget.h>

class QLabel;
class QPushButton;
class QMouseEvent;

class TitleBar final : public QWidget {
  Q_OBJECT

public:
  explicit TitleBar(QWidget *parent = nullptr);

private:
  void loadIcons();
  void initWidgets();

protected:
  void mouseDoubleClickEvent(QMouseEvent *event) override;
  void mousePressEvent(QMouseEvent *event) override;
  void mouseMoveEvent(QMouseEvent *event) override;

  bool eventFilter(QObject *obj, QEvent *event) override;

signals:
  void minimizeRequested();
  void maximizeRequested();
  void closeRequested();

  void moveRequested(QPoint pos);

private:
  // Widgets
  QLabel *m_title;
  UI::IconButton *m_minimizeBtn;
  UI::IconButton *m_maximizeBtn;
  UI::IconButton *m_closeBtn;

  // Mouse
  QPoint m_start_position;
  QPoint m_local_mouse_position;
  bool is_drag = false;

  bool m_is_left_hand;
};

#endif // !WIDGET_TITLEBAR_HPP

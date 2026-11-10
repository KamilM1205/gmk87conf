#ifndef UI_WIDGETS_ROUNDED_WINDOW_HPP
#define UI_WIDGETS_ROUNDED_WINDOW_HPP

#include <QMainWindow>
#include <QtCore/qtmetamacros.h>
#include <QtGui/qevent.h>
#include <QtGui/qwindow.h>

namespace UI {
class RoundedWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit RoundedWindow(QWidget *parent = nullptr);

protected:
  void paintEvent(QPaintEvent *event) override;
};
} // namespace UI

#endif // !UI_WIDGETS_ROUNDED_WINDOW_HPP

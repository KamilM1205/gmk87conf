#ifndef UI_ICON_BUTTON_HPP
#define UI_ICON_BUTTON_HPP

#include <QtCore/qhashfunctions.h>
#include <QtCore/qtmetamacros.h>
#include <QtGui/qcolor.h>
#include <QtGui/qicon.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qwidget.h>

namespace UI {
class IconButton final : public QPushButton {
  Q_OBJECT

  Q_PROPERTY(QColor iconColor READ iconColor WRITE setIconColor)
  Q_PROPERTY(QColor iconColorHover READ iconColorHover WRITE setIconColorHover)
  Q_PROPERTY(
      QColor iconColorClicked READ iconColorClicked WRITE setIconColorClicked)

  friend class IconButtonTest;

public:
  explicit IconButton(QWidget *parent = nullptr);

  void setIcon(const QString &path);

  [[nodiscard]]
  auto iconColor() const -> const QColor;

  [[nodiscard]]
  auto iconColorHover() const -> const QColor;

  [[nodiscard]]
  auto iconColorClicked() const -> const QColor;

  void setIconColor(QColor color);
  void setIconColorHover(QColor color);
  void setIconColorClicked(QColor color);

protected:
  void enterEvent(QEnterEvent *event) override;
  void leaveEvent(QEvent *event) override;

private:
  QColor m_normal_icon_color, m_hovered_icon_color, m_clicked_icon_color;
  QIcon m_normal_icon, m_hovered_icon, m_clicked_icon;
  QString m_icon_path;
  QSize m_icon_size;
  QString m_path;
};
} // namespace UI

#endif // !UI_ICON_BUTTON_HPP

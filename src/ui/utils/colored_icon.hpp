#ifndef UI_COLORED_ICON_HPP
#define UI_COLORED_ICON_HPP

#include <QtCore/qhashfunctions.h>
#include <QtCore/qsize.h>
#include <QtGui/qicon.h>
#include <QtXml/qdom.h>

namespace UI {
class ColoredIcon final {
  friend class ColoredIconTest;

private:
  static std::shared_ptr<QIcon> default_icon;
  static void updateXmlTagColor(QDomDocument doc, const QString &tag_name,
                                const QString &color);

  static auto updateSvgXmlColor(const QString &source, const QString &color)
      -> const QString;

public:
  ColoredIcon() = delete;

  static QIcon DefaultIcon();
  static QIcon CreateIcon(const QString &path, QString const &color,
                          const QSize &size);
};
} // namespace UI

#endif // !UI_COLORED_ICON_HPP

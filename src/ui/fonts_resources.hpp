#ifndef UI_FONTS_RESOURCES_HPP
#define UI_FONTS_RESOURCES_HPP

#include <QFontDatabase>
#include <QString>

namespace UI {
namespace Fonts {

inline const QString RedactionBold =
    QStringLiteral(":/fonts/Redaction-Bold.ttf");
inline const QString RedactionItalic =
    QStringLiteral(":/fonts/Redaction-Italic.ttf");
inline const QString RedactionRegular =
    QStringLiteral(":/fonts/Redaction-Regular.ttf");

inline void RegistrateFonts() {
  QFontDatabase::addApplicationFont(RedactionBold);
  QFontDatabase::addApplicationFont(RedactionItalic);
  QFontDatabase::addApplicationFont(RedactionRegular);
}

} // namespace Fonts
} // namespace UI

#endif // !UI_FONTS_RESOURCES_HPP

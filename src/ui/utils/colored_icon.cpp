#include "colored_icon.hpp"
#include <QByteArray>
#include <QDomDocument>
#include <QFile>
#include <QPainter>
#include <QtCore/qhashfunctions.h>
#include <QtCore/qsize.h>
#include <QtCore/qstringview.h>
#include <QtGui/qicon.h>
#include <QtGui/qpixmap.h>
#include <QtSvg/QSvgRenderer>
#include <memory>
#include <stdexcept>

static const QString DefaultIconPath = ":/icons/rectangle.svg";
std::shared_ptr<QIcon> UI::ColoredIcon::default_icon = nullptr;

QIcon UI::ColoredIcon::DefaultIcon() {
  if (default_icon == nullptr) {
    default_icon = std::make_shared<QIcon>(
        CreateIcon(DefaultIconPath, "#FFFFFF", QSize(45, 45)));
  }

  return *default_icon.get();
}

void UI::ColoredIcon::updateXmlTagColor(QDomDocument doc,
                                        const QString &tag_name,
                                        const QString &color) {
  const auto tag_elem_list = doc.elementsByTagName(tag_name);

  for (auto tag : tag_elem_list) {
    auto elem = tag.toElement();

    if (elem.hasAttribute("fill")) {
      elem.setAttribute("fill", color);
    }

    if (elem.hasAttribute("stroke")) {
      elem.setAttribute("stroke", color);
    }
  }
}

auto UI::ColoredIcon::updateSvgXmlColor(const QString &source,
                                        const QString &color) -> const QString {
  QDomDocument doc;

  if (!doc.setContent(source)) {
    return {};
  }

  updateXmlTagColor(doc, "svg", color);
  updateXmlTagColor(doc, "path", color);
  updateXmlTagColor(doc, "circle", color);
  updateXmlTagColor(doc, "ellipse", color);
  updateXmlTagColor(doc, "rect", color);
  updateXmlTagColor(doc, "line", color);
  updateXmlTagColor(doc, "polygon", color);
  updateXmlTagColor(doc, "polyline", color);

  return doc.toString(2);
}

QIcon UI::ColoredIcon::CreateIcon(const QString &path, QString const &color,
                                  const QSize &size) {
  QFile file(path);

  if (!size.isValid() || size.isEmpty()) {
    throw std::runtime_error(std::format("Incorrect image size: ({}, {}).",
                                         size.width(), size.height()));
  }

  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    throw std::runtime_error(
        std::format("Error open file: \"{}\". Description: {}",
                    path.toStdString(), file.errorString().toStdString()));
  }

  QByteArray content = file.readAll();
  file.close();

  content = updateSvgXmlColor(content, color).toUtf8();

  QSvgRenderer renderer(content);
  if (!renderer.isValid()) {
    throw std::runtime_error(
        std::format("Error occured while creating svg renderer."));
  }

  QPixmap pixmap(size);
  pixmap.fill(Qt::transparent);

  QPainter painter(&pixmap);
  renderer.render(&painter);

  return QIcon(pixmap);
}

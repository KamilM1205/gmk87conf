#include "ui/utils/colored_icon.hpp"
#include <QtCore/qhashfunctions.h>
#include <QtXml/qdom.h>
#include <gtest/gtest.h>
#include <vector>

namespace UI {
class ColoredIconTest : public ::testing::Test {
public:
  std::vector<std::vector<std::string>> SvgSourceTCases = {
      {"circle",
       R"(<svg width="100" height="100" xmlns="http://www.w3.org/2000/svg">
  <circle cx="50" cy="50" r="40" fill="hotpink" />
</svg>)",
       R"(<svg width="100" height="100" xmlns="http://www.w3.org/2000/svg">
  <circle cx="50" cy="50" r="40" fill="#FFFFFF" />
</svg>)"},
      {"rect",
       R"(<svg width="200" height="100" xmlns="http://www.w3.org/2000/svg">
  <rect x="10" y="10" width="180" height="80" rx="15" ry="15" fill="#4a90e2" stroke="#222" stroke-width="2" />
</svg>)",
       R"(<svg width="200" height="100" xmlns="http://www.w3.org/2000/svg">
  <rect x="10" y="10" width="180" height="80" rx="15" ry="15" fill="#FFFFFF" stroke="#FFFFFF" stroke-width="2" />
</svg>)"},
      {"path",
       R"(<svg width="150" height="150" xmlns="http://www.w3.org/2000/svg">
  <path d="M 10 80 Q 75 10, 140 80 T 270 80" fill="none" stroke="green" stroke-width="3" />
</svg>)",
       R"(<svg width="150" height="150" xmlns="http://www.w3.org/2000/svg">
  <path d="M 10 80 Q 75 10, 140 80 T 270 80" fill="#FFFFFF" stroke="#FFFFFF" stroke-width="3" />
</svg>)"},
      {"svg", "<svg fill=\"green\"></svg>", "<svg fill=\"#FFFFFF\"></svg>"},
  };

protected:
  void updateXmlTagColor(QDomDocument doc, const QString &tag_name,
                         const QString &color) {
    ColoredIcon::updateXmlTagColor(doc, tag_name, color);
  }

  auto updateSvgXmlColor(const QString &source, const QString &color)
      -> const QString {
    return UI::ColoredIcon::updateSvgXmlColor(source, color);
  }

  virtual void SetUp() {
    // Normalize test data
    for (auto &tcase : SvgSourceTCases) {
      QDomDocument doc;

      doc.setContent(tcase.at(1).c_str());
      tcase[1] = doc.toString(2).toStdString();

      doc.setContent(tcase.at(2).c_str());
      tcase[2] = doc.toString(2).toStdString();
    }
  }
};

TEST_F(ColoredIconTest, TestXmlTagColor) {
  const std::string TEST_COLOR = "#FFFFFF";
  QDomDocument doc;

  for (const auto &tcase : SvgSourceTCases) {
    ASSERT_TRUE(doc.setContent(QString(tcase.at(1).c_str())));

    updateXmlTagColor(doc, QString(tcase.at(0).c_str()),
                      QString(TEST_COLOR.c_str()));

    EXPECT_EQ(doc.toString(2).toStdString(), tcase.at(2));
  }
}

TEST_F(ColoredIconTest, TestUpdateSvgXmlColor) {
  const std::string TEST_COLOR = "#FFFFFF";

  for (const auto &tcase : SvgSourceTCases) {
    std::string updated = updateSvgXmlColor(QString(tcase.at(1).c_str()),
                                            QString(TEST_COLOR.c_str()))
                              .toStdString();
    EXPECT_EQ(updated, tcase.at(2));
  }
}
} // namespace UI

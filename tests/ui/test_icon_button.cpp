#include "ui/widgets/buttons/icon_button.hpp"
#include <QtCore/qnamespace.h>
#include <QtCore/qpoint.h>
#include <QtGui/qcolor.h>
#include <QtGui/qicon.h>
#include <QtTest/QTest>
#include <QtTest/qtestmouse.h>
#include <QtWidgets/qpushbutton.h>
#include <format>
#include <gtest/gtest.h>

namespace UI {
class IconButtonTest : public ::testing::Test {
public:
  IconButton testButton;

  QIcon getIcon() { return testButton.m_normal_icon; }
  QIcon getHoverIcon() { return testButton.m_hovered_icon; }
  QIcon getClickedIcon() { return testButton.m_clicked_icon; }

protected:
  virtual void SetUp() override { testButton.show(); }
};

TEST_F(IconButtonTest, TestSetupMethods) {
  auto testColor = QColor::fromString("#FFFFFF");

  auto oldIco = getIcon();
  testButton.setIconColor(testColor);
  ASSERT_EQ(testButton.iconColor(), testColor);
  ASSERT_NE(oldIco.data_ptr(), getIcon().data_ptr());

  oldIco = getHoverIcon();
  testButton.setIconColorHover(testColor);
  ASSERT_EQ(testButton.iconColorHover(), testColor);
  ASSERT_NE(oldIco.data_ptr(), getHoverIcon().data_ptr());

  oldIco = getClickedIcon();
  testButton.setIconColorClicked(testColor);
  ASSERT_EQ(testButton.iconColorClicked(), testColor);
  ASSERT_NE(oldIco.data_ptr(), getClickedIcon().data_ptr());
}

TEST_F(IconButtonTest, TestQSSProperties) {
  auto testColor = "#2a2a2a";
  testButton.setObjectName("testButton");

  auto style = R"(
    #testButton {{
      qproperty-iconColor: {};
      qproperty-iconColorHover: {};
      qproperty-iconColorClicked: {};
    }}
  )";
  auto args = std::make_format_args(testColor, testColor, testColor);
  auto fmt_style = std::vformat(style, args);

  testButton.setStyleSheet(fmt_style.c_str());
  testButton.ensurePolished();

  ASSERT_EQ(testButton.iconColor(), QColor::fromString(testColor));
  ASSERT_EQ(testButton.iconColorHover(), QColor::fromString(testColor));
  ASSERT_EQ(testButton.iconColorClicked(), QColor::fromString(testColor));
}

TEST_F(IconButtonTest, TestHaveIcons) {
  // ASSERT_NE(testButton.icon().data_ptr(), nullptr);
  ASSERT_NE(getIcon().data_ptr(), nullptr);
  ASSERT_NE(getHoverIcon().data_ptr(), nullptr);
  ASSERT_NE(getClickedIcon().data_ptr(), nullptr);
}

TEST_F(IconButtonTest, TestHoverEvent) {
  ASSERT_EQ(testButton.icon().data_ptr(), getIcon().data_ptr());

  QTest::mouseMove(&testButton);
  ASSERT_EQ(testButton.icon().data_ptr(), getHoverIcon().data_ptr());
  QTest::mouseMove(&testButton, QPoint(-10, -10));
  ASSERT_EQ(testButton.icon().data_ptr(), getIcon().data_ptr());
}

TEST_F(IconButtonTest, TestClickEvent) {
  bool triggered = false;

  QObject::connect(&testButton, &QPushButton::clicked,
                   [&] { triggered = true; });

  ASSERT_EQ(testButton.icon().data_ptr(), getIcon().data_ptr());
  QTest::mousePress(&testButton, Qt::LeftButton);
  ASSERT_EQ(testButton.icon().data_ptr(), getClickedIcon().data_ptr());
  QTest::mouseRelease(&testButton, Qt::LeftButton);
  ASSERT_EQ(testButton.icon().data_ptr(), getIcon().data_ptr());

  ASSERT_TRUE(triggered);
}

} // namespace UI

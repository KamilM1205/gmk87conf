#include "ui/fonts_resources.hpp"
#include "ui/icon_resources.hpp"
#include <QFile>
#include <gtest/gtest.h>

#define ASSERT_FILE(file)                                                      \
  {                                                                            \
    ASSERT_TRUE(QFile::exists(file));                                          \
  }

TEST(TestResources, TestIconResources) {
  ASSERT_FILE(UI::Icons::DefaultIcon);
  ASSERT_FILE(UI::Icons::CloseIcon);
  ASSERT_FILE(UI::Icons::MaximizeIcon);
  ASSERT_FILE(UI::Icons::MinimizeIcon);
}

TEST(TestResources, TestFontsResources) {
  ASSERT_FILE(UI::Fonts::RedactionBold);
  ASSERT_FILE(UI::Fonts::RedactionItalic);
  ASSERT_FILE(UI::Fonts::RedactionRegular);
}

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG v1.18.0
)

FetchContent_MakeAvailable(googletest)

set(BASE_LIBS
  #  GTest::gtest_main
  GTest::gtest
  ${PROJECT_NAME}_lib
)

set(TEST_SUIT_MAIN_PATH
  ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

set(UI_TEST_SUITS
  colored_icon
  icon_button
)

include(GoogleTest)
include(TestSuite)

AddTestSuite(PATH ${CMAKE_CURRENT_LIST_DIR}/ui MAIN_PATH ${TEST_SUIT_MAIN_PATH} SUITES ${UI_TEST_SUITS} LIBS ${BASE_LIBS})

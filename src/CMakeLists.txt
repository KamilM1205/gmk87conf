set(SOURCES
  core/launcher.cpp
  ui/mainwindow.cpp
  ui/widgets/titlebar.cpp
  ui/widgets/rounded_window.cpp
  ui/widgets/buttons/icon_button.cpp
  ui/utils/colored_icon.cpp
  utils/qrc_output.cpp
)

list(TRANSFORM SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

set(CMAKE_AUTORCC ON)
qt_add_resources(QT_RES_GEN ${PROJECT_SOURCE_DIR}/resources/resources.qrc)
list(APPEND SOURCES ${QT_RES_GEN})

qt_add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

target_link_libraries(${PROJECT_NAME}_lib
  PUBLIC
    Qt6::Widgets
    Qt6::Svg
    Qt6::Xml
    hidapi::hidapi
)

target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

qt_add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${CMAKE_CURRENT_LIST_DIR}/main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

install(TARGETS ${PROJECT_NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION bin
)

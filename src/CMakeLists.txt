set(SOURCES
  core/launcher.cpp
  ui/mainwindow.cpp
  main.cpp
)

list(TRANSFORM SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

qt_add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt6::Widgets
  "-framework IOKit"
  "-framework CoreFoundation"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

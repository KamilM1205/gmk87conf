set(SOURCES
  core/launcher.cpp
  ui/mainwindow.cpp
  main.cpp
)

list(TRANSFORM SOURCES PREPEND ${CMAKE_CURRENT_LIST_DIR}/)

qt_add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${SOURCES})

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt6::Widgets
    hidapi::hidapi
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

install(TARGETS ${PROJECT_NAME}
  BUNDLE DESTINATION .
  RUNTIME DESTINATION bin
)

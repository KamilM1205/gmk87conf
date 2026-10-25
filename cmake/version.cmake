function (get_version FILE_PATH OUT_VAR)
  file(READ "${FILE_PATH}" VERSION_TEXT)
  string(STRIP "${VERSION_TEXT}" VERSION_TEXT)

  if ("${VERSION_TEXT}" STREQUAL "")
    message(FATAL_ERROR "Version is not set")
  endif()

  set(${OUT_VAR} "${VERSION_TEXT}" PARENT_SCOPE)
endfunction()

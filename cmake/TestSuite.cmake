function(AddTestSuite)
  set(oneValueArgs PATH MAIN_PATH)
  set(multiValueArgs SUITES LIBS)
  cmake_parse_arguments(PARSE_ARGV 0 arg "" "${oneValueArgs}" "${multiValueArgs}")

  foreach(suite IN LISTS arg_SUITES)
    set(TEST_SRC
      ${arg_PATH}/test_${suite}.cpp
    )
    if (arg_MAIN_PATH)
      list(APPEND TEST_SRC ${arg_MAIN_PATH})
    endif()

    add_executable(test_${suite} ${TEST_SRC})
    target_link_libraries(test_${suite} PRIVATE ${arg_LIBS})
    gtest_discover_tests(test_${suite})
  endforeach()
endfunction()

add_library(meow SHARED meow.cpp)
target_include_directories(
  meow PUBLIC $<INSTALL_INTERFACE:include>
              $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
target_link_libraries(meow PUBLIC project_properties project_warnings)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_executable(meow_test meow.test.cpp)
  target_link_libraries(meow_test PRIVATE main_test meow)
  add_test(NAME meow COMMAND meow_test)
  if(WIN32)
    add_custom_command(
      TARGET meow_test
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:meow_test>
              $<TARGET_FILE_DIR:meow_test>
      COMMAND_EXPAND_LISTS)
  endif(WIN32)
endif()

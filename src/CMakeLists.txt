add_subdirectory(cat)
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_library(main_test SHARED main.test.cpp)
  target_link_libraries(main_test PUBLIC catch2 project_properties)
endif()

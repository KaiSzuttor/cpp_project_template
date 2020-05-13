add_library(meow SHARED meow.cpp)
target_include_directories(meow 
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  add_library(main_test SHARED main.test.cpp)
  target_link_libraries(main_test PUBLIC doctest)

  add_executable(meow_test meow.test.cpp)
  target_link_libraries(meow_test PRIVATE main_test meow)
  add_test(NAME meow COMMAND meow_test)
endif()

cmake_minimum_required(VERSION 3.10)

project(PROJECTNAME LANGUAGES CXX)

# Link to this library to inherit the properties
add_library(project_properties INTERFACE)
target_compile_features(project_properties INTERFACE cxx_std_14)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake/")

include(StandardProjectSettings)
include(CompilerWarnings)
set_project_warnings(project_warnings)
include(Doxygen)
# enable doxygen
enable_doxygen()
include(StaticAnalyzers)
# sanitizer options if supported by compiler
include(Sanitizers)
enable_sanitizers(project_properties)

option(BUILD_TESTING "Build tests" ON)
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
  enable_testing()
endif()

add_subdirectory(external)
add_subdirectory(src)

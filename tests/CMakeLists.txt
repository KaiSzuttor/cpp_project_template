find_package(Boost 1.58 COMPONENTS unit_test_framework REQUIRED)
include(UnitTest)

unit_test(NAME test1_test SRC test1.cpp DEPENDS PROJECTNAME)

#include <doctest/doctest.h>

#include "cat/sounds/meow.hpp"

TEST_CASE( "meow" ) {
    REQUIRE( Cat::Sounds::meow() == "meow!" );
}

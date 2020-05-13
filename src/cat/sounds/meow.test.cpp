#include <catch2/catch.hpp>

#include "cat/sounds/meow.hpp"

TEST_CASE( "meow" ) {
    REQUIRE( Cat::Sounds::meow() == "meow!" );
}

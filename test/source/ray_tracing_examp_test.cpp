#include <catch2/catch_test_macros.hpp>

#include "lib.hpp"

TEST_CASE("Name is ray_tracing_examp", "[library]")
{
  auto const lib = library {};
  REQUIRE(lib.name == "ray_tracing_examp");
}

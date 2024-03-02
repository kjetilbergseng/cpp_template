#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

auto add(int lhs, int rhs) -> int {
  return lhs + rhs;
}

TEST_CASE("example test") {
  CHECK(add(1, 1) == 2);
}
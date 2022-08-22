#include <doctest.hpp>
#include <serialize/serialize.h>

using doctest::test_suite;

TEST_CASE("Serialize bool (true)" * test_suite("bool")) {
  struct my_struct {
    bool value;
  };

  my_struct s{true};
  auto bytes = serialize(s);
  REQUIRE(bytes.size() == 1);
  REQUIRE(bytes[0] == static_cast<uint8_t>(true));
}

TEST_CASE("Serialize bool (false)" * test_suite("bool")) {
  struct my_struct {
    bool value;
  };

  my_struct s{false};
  auto bytes = serialize(s);
  REQUIRE(bytes.size() == 1);
  REQUIRE(bytes[0] == static_cast<uint8_t>(false));
}
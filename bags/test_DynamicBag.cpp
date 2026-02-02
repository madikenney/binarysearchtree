#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "DynamicBag.hpp"


TEST_CASE("Calling all public members", "[DynamicBag]"){
  DynamicBag<int> b;

  REQUIRE(b.getCurrentSize() == 0);

  b.add(0);
  REQUIRE(b.getCurrentSize() == 1);

  b.remove(0);
  REQUIRE(b.getCurrentSize() == 0);

  REQUIRE(b.isEmpty());
  
  b.add(0);
  b.add(0);
  b.clear();
  REQUIRE(b.isEmpty());

  REQUIRE(b.getFrequencyOf(0)==0);

  b.add(0);
  REQUIRE(b.contains(0));
}

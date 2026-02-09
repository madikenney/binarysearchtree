#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ArrayList.hpp"


TEST_CASE( "Default Constructor", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.getLength() == 0);
}

TEST_CASE("List Argument Constructor", "[ArrayList]" ) {

}

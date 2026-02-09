#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ArrayList.hpp"


TEST_CASE( "Default Constructor", "[ArrayList]" ) {

  ArrayList<int> list;
  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());
}

TEST_CASE("List Argument Constructor", "[ArrayList]" ) {
  ArrayList<int> a;
  a.insert(0,1);
  a.insert(1,2);
  a.insert(2,3);
  
  ArrayList<int> b(a);
  REQUIRE(b.getLength() == 3);
  REQUIRE(b.getEntry(0) == 1);
}

TEST_CASE("Insert & Get Entry", "[ArrayList]" ) {
  ArrayList<int> a;
  a.insert(0,1);
  a.insert(1,2);
  a.insert(2,3);

  REQUIRE(a.getEntry(0) == 1);
  REQUIRE(a.getEntry(1) == 2);
  REQUIRE(a.getEntry(2) == 3);
}

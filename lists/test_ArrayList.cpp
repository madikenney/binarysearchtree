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

TEST_CASE("Invalid Insert & Get Entry", "[ArrayList]" ) {
  ArrayList<int> a;
  REQUIRE_THROWS_AS(a.insert(10,1),std::out_of_range);
  REQUIRE_THROWS_AS(a.getEntry(10),std::out_of_range);
}

TEST_CASE("Copy Assignment Operator", "[ArrayList]" ) {
  // implicitly tests swap(), which is used in the copy-swap idiom
  
  ArrayList<int> a;
  a.insert(0,1);
  a.insert(1,2);
  a.insert(2,3);

  ArrayList<int> b;
  b.insert(0,2);
  b.insert(1,3);
  b.insert(2,4);

  b = a;

  REQUIRE(b.getLength() == 3);
  REQUIRE(b.getEntry(0) == 1);
  REQUIRE(b.getEntry(1) == 2);
  REQUIRE(b.getEntry(2) == 3);
}

TEST_CASE("Clear", "[ArrayList]" ) {
  // implicitly tests swap(), which is used in the copy-swap idiom
  
  ArrayList<int> a;
  a.insert(0,1);
  a.insert(1,2);
  a.insert(2,3);

  a.clear();

  REQUIRE(a.getLength() == 0);
  REQUIRE_THROWS_AS(a.getEntry(1),std::out_of_range);
}
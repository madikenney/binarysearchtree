#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LinkedList.hpp"


TEST_CASE( "Default Constructor", "[LinkedList]" ) {

    LinkedList<int> a;

    REQUIRE(a.getLength()==0);
    REQUIRE(a.isEmpty());
}

TEST_CASE( "Insert & getEntry", "[LinkedList]" ) {

    LinkedList<int> a;

    a.insert(0,3);
    a.insert(0,2);
    a.insert(0,1);

    REQUIRE(a.getEntry(0)==1);
    REQUIRE(a.getEntry(1)==2);
    REQUIRE(a.getEntry(2)==3);
    REQUIRE(a.getLength()==3);
}

TEST_CASE( "SetValue", "[LinkedList]" ) {

    LinkedList<int> a;

    // 1 2 3
    a.insert(0,1);
    a.insert(1,2);
    a.insert(2,3);

    a.setEntry(1,10);
    REQUIRE(a.getEntry(0)==1);
    REQUIRE(a.getEntry(1)==10);
    REQUIRE(a.getEntry(2)==3);
    REQUIRE(a.getLength()==3);
}

TEST_CASE( "Remove", "[LinkedList]" ) {

    LinkedList<int> a;

    // 1 2 3
    a.insert(0,1);
    a.insert(1,2);
    a.insert(2,3);

    a.remove(1);
    REQUIRE(a.getEntry(0)==1);
    REQUIRE(a.getEntry(1)==3);
    REQUIRE_THROWS_AS(a.getEntry(2),std::out_of_range);
    REQUIRE(a.getLength()==2);
}
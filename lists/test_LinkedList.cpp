#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LinkedList.hpp"


TEST_CASE( "Default Constructor", "[LinkedList]" ) {

    LinkedList<int> a;

    REQUIRE(a.getLength()==0);
    REQUIRE(a.isEmpty());
}

TEST_CASE( "Insert", "[LinkedList]" ) {

    LinkedList<int> a;

    a.insert(0,3);
    a.insert(0,2);
    a.insert(0,1);

    REQUIRE(a.getEntry(0)==1);
    REQUIRE(a.getEntry(1)==2);
    REQUIRE(a.getEntry(2)==3);
    REQUIRE(a.getLength()==3);
}
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "LinkedList.hpp"


TEST_CASE( "Default Constructor", "[LinkedList]" ) {

    LinkedList<int> a;

    REQUIRE(a.getLength()==0);
    REQUIRE(a.isEmpty());
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "List.hpp"
#include "sort.hpp"

/* Provided test cases */
TEST_CASE("Sort: Test move entry", "[sorting]") {
  List<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 4);
  lst.insert(2, 10);
  lst.insert(3, 25);
  lst.insert(4, 11);

  // move forward
  lst.moveEntry(0, 2);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(0) == 4);
  REQUIRE(lst.getEntry(1) == 10);
  REQUIRE(lst.getEntry(2) == 100);
  REQUIRE(lst.getEntry(3) == 25);
  REQUIRE(lst.getEntry(4) == 11);

  // move backward
  lst.moveEntry(4, 0);

  REQUIRE(lst.getLength() == 5);
  REQUIRE(lst.getEntry(0) == 11);
  REQUIRE(lst.getEntry(1) == 4);
  REQUIRE(lst.getEntry(2) == 10);
  REQUIRE(lst.getEntry(3) == 100);
  REQUIRE(lst.getEntry(4) == 25);

  // invalid moves
  REQUIRE_THROWS_AS(lst.moveEntry(5,0), std::out_of_range);
  REQUIRE_THROWS_AS(lst.moveEntry(0,5), std::out_of_range);
}


TEST_CASE("Sort: Integer sorting", "[sorting]"){

  List<int> lst;

  lst.insert(0, 100);
  lst.insert(1, 25);
  lst.insert(2, 10);
  lst.insert(3, 4);
  lst.insert(4, 11);

  quick_sort(lst, 0, lst.getLength()-1);

  // check sorted list
  REQUIRE(lst.getEntry(0) == 4);
  REQUIRE(lst.getEntry(1) == 10);
  REQUIRE(lst.getEntry(2) == 11);
  REQUIRE(lst.getEntry(3) == 25);
  REQUIRE(lst.getEntry(4) == 100);
}

TEST_CASE("Sort: Test partitioning", "[sorting]") {
    List<int> lst;
  
    lst.insert(0, 100);
    lst.insert(1, 30);
    lst.insert(2, 50);
    lst.insert(3, 4);
    lst.insert(4, 256);
    lst.insert(5, 1);
    lst.insert(6, 0);
    lst.insert(7, 25);
    lst.insert(8, 10);
    lst.insert(9, 512);
  
    // partition whole list
    int test = partition(lst, 0, lst.getLength()-1);
    // first item (100) should now be at index 7
    REQUIRE(test == 7);
}

/* Your test cases here */
TEST_CASE("Sort: Test character sort", "[sorting]") {
    List<int> lst;
  
    lst.insert(0, 'a');
    lst.insert(1, 'd');
    lst.insert(2, 'e');
    lst.insert(3, 'b');
    lst.insert(4, 'z');
    lst.insert(5, 'f');
    lst.insert(6, 'y');
  
    // quick sort list
    quick_sort(lst, 0, lst.getLength()-1);

    // check correct placement
    REQUIRE(lst.getEntry(0) == 'a');
    REQUIRE(lst.getEntry(1) == 'b');
    REQUIRE(lst.getEntry(2) == 'd');
    REQUIRE(lst.getEntry(3) == 'e');
    REQUIRE(lst.getEntry(4) == 'f');
    REQUIRE(lst.getEntry(5) == 'y');
    REQUIRE(lst.getEntry(6) == 'z');
}

TEST_CASE("Sort: Test short list & reverse order", "[sorting]") {
    List<int> lst;
  
    lst.insert(0, 3);
    lst.insert(1, 2);
    lst.insert(2, 1);
  
    // quick sort list
    quick_sort(lst, 0, lst.getLength()-1);

    // check correct placement
    REQUIRE(lst.getEntry(0) == 1);
    REQUIRE(lst.getEntry(1) == 2);
    REQUIRE(lst.getEntry(2) == 3);
}

TEST_CASE("Sort: Test mixed data", "[sorting]") {
    List<int> lst;
  
    lst.insert(0, 3);
    lst.insert(1, 'b');
    lst.insert(2, 'B');
    lst.insert(3, 1);
  
    // quick sort list
    quick_sort(lst, 0, lst.getLength()-1);

    // check correct placement
    // in order based on ascii values?
    REQUIRE(lst.getEntry(0) == 1);
    REQUIRE(lst.getEntry(1) == 3);
    REQUIRE(lst.getEntry(2) == 'B');
    REQUIRE(lst.getEntry(3) == 'b');
}
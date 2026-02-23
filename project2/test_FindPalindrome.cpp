#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "FindPalindrome.hpp"
#include <vector>

TEST_CASE("Test add string", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	
	REQUIRE_FALSE(b.add("a"));
	REQUIRE_FALSE(b.add("AA"));
	REQUIRE_FALSE(b.add("AaA"));
	
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test add vector", "[FindPalindrome]"){
	FindPalindrome b;

	std::vector<std::string> v = {"a","AA","AaA"};	

	REQUIRE(b.add(v));
	REQUIRE_FALSE(b.add(v));
	
	REQUIRE(b.number() == 6);
}

TEST_CASE("Test sentences", "[FindPalindrome]"){
	FindPalindrome a;

	std::vector<std::string> v = {"TaCo","cAt"};	

	REQUIRE(a.add(v));
	REQUIRE_FALSE(a.add(v));
	
	REQUIRE(a.number() == 1);
}

TEST_CASE("Test invalid words", "[FindPalindrome]"){
	FindPalindrome a;

	REQUIRE_FALSE(a.add("123"));
	REQUIRE_FALSE(a.add(""));
	REQUIRE_FALSE(a.add("-12dk9ajnd3_"));
	
	REQUIRE(a.number() == 0);
}
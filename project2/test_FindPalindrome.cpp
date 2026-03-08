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

TEST_CASE("Test clear", "[FindPalindrome]"){
	FindPalindrome b;

	REQUIRE(b.add("a"));
	REQUIRE(b.add("AA"));
	REQUIRE(b.add("AaA"));
	REQUIRE(b.number() == 6);

	b.clear();
	REQUIRE(b.number() == 0);
}

TEST_CASE("Test cut tests", "[FindPalindrome]"){
	FindPalindrome b;
	REQUIRE_FALSE(b.cutTest1({"aaa","bbb"}));
	REQUIRE(b.cutTest1({"aaaa","bbb"}));

	REQUIRE(b.cutTest2({"aa","bb"},{"aaa","bbb"}));
	REQUIRE_FALSE(b.cutTest2({"aa","bb"},{"ccc","ddd"}));
}

TEST_CASE("Test toVector", "[FindPalindrome]"){
	FindPalindrome b;
	std::vector<std::string> v = {"car","race"};	
	b.add(v);

	std::vector< std::vector<std::string> > a = {{"race","car"}};
	REQUIRE(b.toVector() == a);
}

TEST_CASE("Checkoff!", "[FindPalindrome]"){
	FindPalindrome c;
	std::vector<std::string> a = {"ww", "bb", "a"};
	std::vector<std::string> b = {"w", "b"};
	
	REQUIRE(c.cutTest2(a,b));
}
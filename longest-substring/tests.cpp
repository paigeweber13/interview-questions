//
// Created by Paige Riley Weber on 7/23/21.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include <catch2/catch.hpp>

#include "longestSubstring.hpp"

TEST_CASE( "Length of longest substring is computed", "[longest_substr]" ) {
REQUIRE(lengthOfLongestSubstring("abcabcbb") == 3 );
REQUIRE(lengthOfLongestSubstring("pwwkew") == 3);
REQUIRE(lengthOfLongestSubstring(" ") == 1);
REQUIRE(lengthOfLongestSubstring("au") == 2);
}

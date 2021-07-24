//
// Created by Paige Riley Weber on 7/23/21.
//

#include "longestSubstring.hpp"

int lengthOfLongestSubstring(std::string s) {
  std::set<char> seenChars;
  size_t maxSubstringLength = 0;

  for (size_t i = 0; i < s.size(); i++) {
    seenChars.clear();

    for (size_t j = i; j < s.size(); j++) {
      if (seenChars.count(s[j]) == 0) {
        // set does NOT contain s[j]
        seenChars.insert(s[j]);
      }
      else {
        // set DOES contain s[j]
        if (seenChars.size() > maxSubstringLength) {
          maxSubstringLength = seenChars.size();
        }
        break;
      }
    }

    // Above, we only trigger the check on finding a non-unique character.
    // Including the check here as well ensures that if we don't find a
    // non-unique character before the end of the string, we will still make the
    // comparison and update the max length if needed.

    if (seenChars.size() > maxSubstringLength) {
      maxSubstringLength = seenChars.size();
    }
  }

  return maxSubstringLength;
}

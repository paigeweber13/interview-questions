#include <iostream>
#include <set>
#include <string>
#include <vector>


// function prototypes
bool testTrue(bool testCase, std::string testName);

template <typename T>
bool testEqual(T actual, T expected, std::string testName);


// interview question
bool allCharsUniqueSet(std::string str) {
  std::set<char> chars;

  for (const char& c : str) {
    auto insertionResult = chars.insert(c);
    if (insertionResult.second == false) {
      // the second entry in the pair is false if an equivalent element already
      // existed
      return false;
    }
  }

  return true;
}

bool allCharsUniqueDoubleFor(std::string str) {
  for (size_t i = 0; i < str.size(); i++) {      
    for (size_t j = i + 1; j < str.size(); j++) {      
      if(str[i] == str[j]) {
        return false;
      }
    }
  }

  return true;
}

bool allCharsUniqueSimpleHashMap(std::string str) {
  // assuming ascii: there are only 256 possible characters
  const size_t NUM_CHARS = 256;
  bool charWasUsed[NUM_CHARS];

  for (size_t i = 0; i < NUM_CHARS; i++) {
    charWasUsed[i] = false;
  }

  for (const char& c : str) {
    // using char as index to our set
    if(charWasUsed[static_cast<unsigned>(c)]) {
      // character already used!
      return false;
    }

    charWasUsed[static_cast<unsigned>(c)] = true;
  }

  return true;
}


// main
int main(int argc, char** argv) {
  std::vector<std::string> uniqueStrings = {
    "abcdefghijk",
    "quickbrownlazy",
    "poiu;lkj.,m$",
    "Sphinxofblckquartz,jdgemyvw.",
    "Waltz,bdnymphforquckjigsvex.",
  };
  std::vector<std::string> nonUniqueStrings = {
    "eeee",
    "abcdefghia",
    "zxcvbasdfz",
    "abcdberwq",
    "abcd efgh ijk",
  };

  for(size_t i = 0; i < uniqueStrings.size(); i++) {
    testTrue(allCharsUniqueSet(uniqueStrings[i]), "UNIQUE " +
      std::to_string(i) + ":     set implementation reports string '" 
      + uniqueStrings[i] + "' as unique");
  }
  for(size_t i = 0; i < nonUniqueStrings.size(); i++) {
    testTrue(!allCharsUniqueSet(nonUniqueStrings[i]), "NON-UNIQUE " + 
      std::to_string(i) + ": set implementation reports string '" 
      + nonUniqueStrings[i] + "' as non-unique");
  }

  for(size_t i = 0; i < uniqueStrings.size(); i++) {
    testTrue(allCharsUniqueDoubleFor(uniqueStrings[i]), "UNIQUE " +
      std::to_string(i) + ":     double for loop implementation reports " 
      "string '" + uniqueStrings[i] + "' as unique");
  }
  for(size_t i = 0; i < nonUniqueStrings.size(); i++) {
    testTrue(!allCharsUniqueDoubleFor(nonUniqueStrings[i]), "NON-UNIQUE " + 
      std::to_string(i) + ": double for loop implementation reports string '" 
      + nonUniqueStrings[i] + "' as non-unique");
  }

  for(size_t i = 0; i < uniqueStrings.size(); i++) {
    testTrue(allCharsUniqueSimpleHashMap(uniqueStrings[i]), "UNIQUE " +
      std::to_string(i) + ":     simple hash map implementation reports " 
      "string '" + uniqueStrings[i] + "' as unique");
  }
  for(size_t i = 0; i < nonUniqueStrings.size(); i++) {
    testTrue(!allCharsUniqueSimpleHashMap(nonUniqueStrings[i]), "NON-UNIQUE " + 
      std::to_string(i) + ": simple hash map implementation reports string '" 
      + nonUniqueStrings[i] + "' as non-unique");
  }

  return 0;
}


// implementations of test functions, not important for interview question
bool testTrue(bool testCase, std::string testName) {
  if(testCase) {
    std::cout << "PASSED: " << testName << std::endl;
    return true;
  }
  else {
    std::cout << "FAILED: " << testName << std::endl;
    return false;
  }
}

template <typename T>
bool testEqual(T actual, T expected, std::string testName) {
  if (testTrue(actual == expected, testName)) {
    return true;
  }
  else {
    std::cout << "        " << "EXPECTED : " << expected << std::endl;
    std::cout << "        " << "ACTUAL   : " << actual << std::endl;
    return false;
  }
}

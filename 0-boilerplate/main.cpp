#include <iostream>


// function prototypes
bool testTrue(bool testCase, std::string testName);

template <typename T>
bool testEqual(T actual, T expected, std::string testName);


// interview question functions go here


// main
int main(int argc, char** argv) {
  std::string helloString = "Hello world!";
  std::cout << helloString << std::endl;
  testTrue(helloString > "Hello world", "helloString is greater than hello "
    "without exclamation point");
  testEqual(helloString.size(), static_cast<size_t>(12), "helloString has "
    "size 12");
  testEqual(helloString, std::string("Hello world!"), "helloString equals "
    "'Hello world!'.");
  testEqual(helloString, std::string("Hello world"), "(SHOULD FAIL) "
    "helloString equals 'Hello world' (without exclamation point).");
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


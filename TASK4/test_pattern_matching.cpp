#include <iostream>
#include <string>
using namespace std;

// Declaration of the function in pattern_matching.cpp
int findPattern(const string& text, const string& pattern);

void runTest(
    const string& testName,
    const string& text,
    const string& pattern,
    int expected)
{
    int actual = findPattern(text, pattern);

    cout << testName << ": "
         << (actual == expected ? "PASS" : "FAIL")
         << endl;
}

int main()
{
    // Test 1: Pattern at the beginning
    runTest(
        "Pattern at beginning",
        "hello world",
        "hello",
        0
    );

    // Test 2: Pattern at the end
    runTest(
        "Pattern at end",
        "hello world",
        "world",
        6
    );

    // Test 3: Pattern not present
    runTest(
        "Pattern not present",
        "hello world",
        "data",
        -1
    );

    // Test 4: Empty pattern
    runTest(
        "Empty pattern",
        "hello world",
        "",
        0
    );

    return 0;
}
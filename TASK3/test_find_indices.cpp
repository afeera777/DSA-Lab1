#include <iostream>
#include <vector>
using namespace std;

// Declaration of the function implemented in find_indices.cpp
vector<int> findAllIndices(const vector<int>& values, int key);

bool areEqual(const vector<int>& actual, const vector<int>& expected)
{
    return actual == expected;
}

int main()
{
    // Test 1 of Multiple occurrences
    vector<int> test1 = {4, 2, 4, 7, 4};
    vector<int> expected1 = {0, 2, 4};

    cout << "Multiple occurrences: "
         << (areEqual(findAllIndices(test1, 4), expected1)
                 ? "PASS"
                 : "FAIL")
         << endl;

    // Test 2: Key not present
    vector<int> test2 = {1, 2, 3};
    vector<int> expected2 = {};

    cout << "Key not present: "
         << (areEqual(findAllIndices(test2, 7), expected2)
                 ? "PASS"
                 : "FAIL")
         << endl;

    // Test 3: Empty array
    vector<int> test3 = {};
    vector<int> expected3 = {};

    cout << "Empty array: "
         << (areEqual(findAllIndices(test3, 5), expected3)
                 ? "PASS"
                 : "FAIL")
         << endl;

    return 0;
}
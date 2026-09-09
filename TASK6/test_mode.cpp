#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

int findMode(const vector<int>& numbers);

void runTest(
    const string& testName,
    const vector<int>& numbers,
    int expected
)
{
    int result = findMode(numbers);

    cout << testName << ": "
         << (result == expected ? "PASS" : "FAIL")
         << endl;
}

int main()
{
    runTest(
        "Normal array",
        {1, 2, 2, 3, 4},
        2
    );

    runTest(
        "Negative numbers",
        {-1, -1, -1, 2, 3},
        -1
    );

    runTest(
        "All values identical",
        {7, 7, 7, 7},
        7
    );

    runTest(
        "Single element",
        {10},
        10
    );

    try
    {
        findMode({});
        cout << "Empty array: FAIL" << endl;
    }
    catch (const invalid_argument&)
    {
        cout << "Empty array: PASS" << endl;
    }

    return 0;
}
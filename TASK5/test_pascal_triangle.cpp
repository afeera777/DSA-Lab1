#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generatePascalTriangle(int rows);

bool trianglesAreEqual(
    const vector<vector<int>>& actual,
    const vector<vector<int>>& expected)
{
    return actual == expected;
}

void runTest(
    const string& testName,
    int rows,
    const vector<vector<int>>& expected)
{
    vector<vector<int>> actual =
        generatePascalTriangle(rows);

    if (trianglesAreEqual(actual, expected))
    {
        cout << testName << ": PASS" << endl;
    }
    else
    {
        cout << testName << ": FAIL" << endl;
    }
}

int main()
{
    runTest(
        "One row",
        1,
        {
            {1}
        }
    );

    runTest(
        "Five rows",
        5,
        {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1}
        }
    );

    runTest(
        "Zero rows",
        0,
        {}
    );

    runTest(
        "Six rows",
        6,
        {
            {1},
            {1, 1},
            {1, 2, 1},
            {1, 3, 3, 1},
            {1, 4, 6, 4, 1},
            {1, 5, 10, 10, 5, 1}
        }
    );

    return 0;
}
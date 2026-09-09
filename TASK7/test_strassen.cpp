#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix multiplyStrassen(const Matrix& a, const Matrix& b);

void runTest(
    const string& testName,
    const Matrix& a,
    const Matrix& b,
    const Matrix& expected
)
{
    Matrix result = multiplyStrassen(a, b);

    cout << testName << ": "
         << (result == expected ? "PASS" : "FAIL")
         << endl;
}

int main()
{
    runTest(
        "Two by two matrices",
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        },
        {
            {19, 22},
            {43, 50}
        }
    );

    runTest(
        "One by one matrices",
        {
            {5}
        },
        {
            {4}
        },
        {
            {20}
        }
    );

    runTest(
        "Three by three identity matrix",
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1}
        },
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    );

    runTest(
        "Matrices containing zeros",
        {
            {0, 0},
            {0, 0}
        },
        {
            {1, 2},
            {3, 4}
        },
        {
            {0, 0},
            {0, 0}
        }
    );

    return 0;
}
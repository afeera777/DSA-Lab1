#include <vector>
using namespace std;

vector<vector<int>> generatePascalTriangle(int rows)
{
    vector<vector<int>> triangle;

    if (rows <= 0)
    {
        return triangle;
    }

    for (int i = 0; i < rows; i++)
    {
        vector<int> currentRow(i + 1, 1);

        for (int j = 1; j < i; j++)
        {
            currentRow[j] =
                triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(currentRow);
    }

    return triangle;
}
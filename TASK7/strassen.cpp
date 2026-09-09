#include <vector>
#include <stdexcept>
using namespace std;

using Matrix = vector<vector<int>>;

Matrix addMatrices(const Matrix& a, const Matrix& b)
{
    int n = a.size();
    Matrix result(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    return result;
}

Matrix subtractMatrices(const Matrix& a, const Matrix& b)
{
    int n = a.size();
    Matrix result(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    return result;
}

Matrix strassenRecursive(const Matrix& a, const Matrix& b)
{
    int n = a.size();

    if (n == 1)
    {
        return {{a[0][0] * b[0][0]}};
    }

    int half = n / 2;

    Matrix a11(half, vector<int>(half));
    Matrix a12(half, vector<int>(half));
    Matrix a21(half, vector<int>(half));
    Matrix a22(half, vector<int>(half));

    Matrix b11(half, vector<int>(half));
    Matrix b12(half, vector<int>(half));
    Matrix b21(half, vector<int>(half));
    Matrix b22(half, vector<int>(half));

    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + half];
            a21[i][j] = a[i + half][j];
            a22[i][j] = a[i + half][j + half];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + half];
            b21[i][j] = b[i + half][j];
            b22[i][j] = b[i + half][j + half];
        }
    }

    Matrix m1 = strassenRecursive(
        addMatrices(a11, a22),
        addMatrices(b11, b22)
    );

    Matrix m2 = strassenRecursive(
        addMatrices(a21, a22),
        b11
    );

    Matrix m3 = strassenRecursive(
        a11,
        subtractMatrices(b12, b22)
    );

    Matrix m4 = strassenRecursive(
        a22,
        subtractMatrices(b21, b11)
    );

    Matrix m5 = strassenRecursive(
        addMatrices(a11, a12),
        b22
    );

    Matrix m6 = strassenRecursive(
        subtractMatrices(a21, a11),
        addMatrices(b11, b12)
    );

    Matrix m7 = strassenRecursive(
        subtractMatrices(a12, a22),
        addMatrices(b21, b22)
    );

    Matrix c11 = addMatrices(
        subtractMatrices(addMatrices(m1, m4), m5),
        m7
    );

    Matrix c12 = addMatrices(m3, m5);
    Matrix c21 = addMatrices(m2, m4);

    Matrix c22 = addMatrices(
        addMatrices(subtractMatrices(m1, m2), m3),
        m6
    );

    Matrix result(n, vector<int>(n));

    for (int i = 0; i < half; i++)
    {
        for (int j = 0; j < half; j++)
        {
            result[i][j] = c11[i][j];
            result[i][j + half] = c12[i][j];
            result[i + half][j] = c21[i][j];
            result[i + half][j + half] = c22[i][j];
        }
    }

    return result;
}

Matrix multiplyStrassen(const Matrix& a, const Matrix& b)
{
    if (a.empty() || b.empty() || a.size() != b.size())
    {
        throw invalid_argument(
            "Matrices must be non-empty and have equal dimensions."
        );
    }

    int originalSize = a.size();

    for (const auto& row : a)
    {
        if (row.size() != originalSize)
        {
            throw invalid_argument("Matrices must be square.");
        }
    }

    for (const auto& row : b)
    {
        if (row.size() != originalSize)
        {
            throw invalid_argument("Matrices must be square.");
        }
    }

    int paddedSize = 1;

    while (paddedSize < originalSize)
    {
        paddedSize *= 2;
    }

    Matrix paddedA(paddedSize, vector<int>(paddedSize, 0));
    Matrix paddedB(paddedSize, vector<int>(paddedSize, 0));

    for (int i = 0; i < originalSize; i++)
    {
        for (int j = 0; j < originalSize; j++)
        {
            paddedA[i][j] = a[i][j];
            paddedB[i][j] = b[i][j];
        }
    }

    Matrix paddedResult = strassenRecursive(paddedA, paddedB);
    Matrix result(originalSize, vector<int>(originalSize));

    for (int i = 0; i < originalSize; i++)
    {
        for (int j = 0; j < originalSize; j++)
        {
            result[i][j] = paddedResult[i][j];
        }
    }

    return result;
}
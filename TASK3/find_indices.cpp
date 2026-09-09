#include <vector>
using namespace std;

// Returns every index where the given key occurs.
vector<int> findAllIndices(const vector<int>& values, int key)
{
    vector<int> indices;

    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] == key)
        {
            indices.push_back(i);
        }
    }

    return indices;
}
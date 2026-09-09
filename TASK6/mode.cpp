#include <vector>
#include <unordered_map>
#include <stdexcept>
using namespace std;

int findMode(const vector<int>& numbers)
{
    if (numbers.empty())
    {
        throw invalid_argument("The array cannot be empty.");
    }

    unordered_map<int, int> frequencies;

    int mode = numbers[0];
    int highestFrequency = 0;

    for (int number : numbers)
    {
        frequencies[number]++;

        if (frequencies[number] > highestFrequency)
        {
            highestFrequency = frequencies[number];
            mode = number;
        }
    }

    return mode;
}
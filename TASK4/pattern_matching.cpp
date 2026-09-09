#include <string>
using namespace std;

// Finds the first occurrence of a pattern in the given text.
// Returns the starting index or -1 if the pattern is not found.
int findPattern(const string& text, const string& pattern)
{
    // An empty pattern is considered to start at index 0.
    if (pattern.empty())
    {
        return 0;
    }

    // A longer pattern cannot occur inside a shorter text.
    if (pattern.length() > text.length())
    {
        return -1;
    }

    // Check every possible starting position in the text.
    for (int i = 0; i <= text.length() - pattern.length(); i++)
    {
        bool matched = true;

        // Compare the pattern with the text character by character.
        for (int j = 0; j < pattern.length(); j++)
        {
            if (text[i + j] != pattern[j])
            {
                matched = false;
                break;
            }
        }

        if (matched)
        {
            return i;
        }
    }

    return -1;
}
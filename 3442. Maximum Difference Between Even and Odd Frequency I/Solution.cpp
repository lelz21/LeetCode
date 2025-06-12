#include <string>
#include <map>

class Solution {
public:
    int maxDifference(const std::string &s) 
    {
        std::map<char, int> freq;

        for (const char &c : s)
        {
            if (!freq.contains(c))
                freq[c] = 0;
            freq[c]++;
        }

        std::pair<char, int> a1 = {0, 0};
        std::pair<char, int> a2 = {0, 0};
        bool even = false;
        for (auto it = freq.begin(); it != freq.end(); ++it)
        {
            even = it->second % 2 == 0;
            if (!even && (a1.second == 0 || it->second - a2.second > a1.second - a2.second))
                a1 = *it;

            if (even && (a2.second == 0 || a1.second - it->second > a1.second - a2.second))
                a2 = *it;
        }

        return a1.second - a2.second;
    }
};
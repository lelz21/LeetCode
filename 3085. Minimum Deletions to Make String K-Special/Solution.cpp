#include <string>
#include <map>

class Solution 
{
public:
    int minimumDeletions(const std::string &word, int k) 
    {
        std::map<char, int> freq;
        for (const char &c : word)
        {
            if (!freq.contains(c))
                freq[c] = 0;
            freq[c]++;
        }

        int min = INT_MAX;
        for (auto i = freq.begin(); i != freq.end(); ++i)
        {
            int del = 0;
            for (auto j = freq.begin(); j != freq.end(); ++j)
            {
                if (j->second < i->second)
                    del += j->second;
                else if (j->second > i->second + k)
                    del += (j->second - (i->second + k));
            }
            min = std::min(del, min);
        }

        return min;
    }
};
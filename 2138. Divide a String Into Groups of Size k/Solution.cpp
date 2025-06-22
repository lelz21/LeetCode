#include <vector>
#include <string>

class Solution 
{
public:
    std::vector<std::string> divideString(std::string &s, int k, char fill) 
    {
        std::vector<std::string> vec;
        for (int j = 0; j < s.size(); j+=k)
        {
            std::string tmp;
            for (int i = 0; i < k; ++i)
            {
                if (j + i < s.size())
                    tmp.push_back(s[j + i]);
                else
                    tmp.push_back(fill);
            }
            vec.push_back(tmp);
        }

        return vec;
    }
};
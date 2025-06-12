#include <string>
#include <map>
#include <stack>

class Solution 
{
public:
    std::string clearStars(std::string &s) 
    {
        if(s.empty())
            return s;

        std::map<char, std::stack<int>> smallestPos;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*')
            {
                auto it = smallestPos.begin();
                while ((*it).second.empty())
                    ++it;
                s[(*it).second.top()] = '*';
                (*it).second.pop();
            }
            else
            {
                smallestPos[s[i]].push(i);
            }
        }

        std::string result;
        for (const char &c : s)
        {
            if (c != '*')
                result.push_back(c);
        }

        return result;
    }
};
#include <climits>
#include <algorithm>

class Solution 
{
    int remap(int num, int d1, int d2)
    {
        int remapped = 0;
        int decimal = 1;
        int tmp = 0;
        while (num > 0)
        {
            int current = num % 10;
            num = num / 10;
            
            // check for leading 0's
            tmp = (current == d1 ? d2 : current) * decimal;

            remapped = tmp + remapped;
            decimal *= 10;
        }
        //leading 0's
        if (tmp == 0)
            return -1;
        return remapped;
    }

public:
    int maxDiff(int num) 
    {
        long a = INT_MIN;
        long b = INT_MAX;

        for (int x = 0; x < 10; ++x)
        {
            for (int y = 0; y < 10; ++y)
            {
                long r = remap(num, x, y);
                if (r > 0) 
                {
                    a = std::max(r, a);
                    b = std::min(r, b);
                }
            }
        }
        return a - b;
    }
};
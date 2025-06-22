#include <algorithm>
#include <limits>

class Solution 
{
    int remap(int num, int d1, int d2)
    {
        int remapped = 0;
        int decimal = 1;
        while (num > 0)
        {
            int current = num % 10;
            num = num / 10;
            remapped = (current == d1 ? d2 : current) * decimal + remapped;
            decimal *= 10;
        }

        return remapped;
    }
public:
    int minMaxDifference(int num) 
    {
        int min = std::numeric_limits<int>::max();
        int max = std::numeric_limits<int>::min();
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                int remapped = remap(num, i, j);
                min = std::min(remapped, min);
                max = std::max(remapped, max);
            }
        }

        return max - min;
    }
};
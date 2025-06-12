#include <vector>
#include <cmath>

class Solution
{
public:
    int maxAdjacentDistance(std::vector<int>& nums) 
    {
        int max = 0;
        int size = nums.size();
        for (int i = 0; i < size - 1; ++i)
        {
            int absdiff = abs(nums[i] - nums[i + 1]);
            if (absdiff > max)
                max = absdiff;
        }

        int last = abs(nums[size - 1] - nums[0]);
        if (last > max)
            return last;
        return max;
    }
};
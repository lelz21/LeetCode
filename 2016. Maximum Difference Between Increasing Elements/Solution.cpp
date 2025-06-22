#include <vector>
#include <limits>

class Solution 
{
public:
    int maximumDifference(const std::vector<int>& nums) 
    {
        int max = std::numeric_limits<int>::min();
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                int diff = nums[j] - nums[i];
                if (diff > max)
                    max = diff;
            }
        }
        if (max > 0)
            return max;
        else
            return -1;
    }
};
#include <vector>
#include <algorithm>

class Solution
{
public:
    int partitionArray(std::vector<int>& nums, int k) 
    {
        std::sort(nums.begin(), nums.end());
        int start = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] - nums[start] > k)
            {
                start = i;
                counter++;
            }
        }

        return counter + 1;
    }
};
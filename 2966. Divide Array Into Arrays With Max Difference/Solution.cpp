#include <vector>
#include <algorithm>

class Solution 
{
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) 
    {
        std::vector<std::vector<int>> arr;
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int left = 0; left < size; left+=3)
        {
            int right = left + 2;
            if (nums[left] + k < nums[right])
                return std::vector<std::vector<int>>();
            else
                arr.push_back({nums[left], nums[left + 1], nums[right]});
        }

        return arr;
    }
};
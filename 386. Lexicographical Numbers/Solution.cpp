#include <vector>

class Solution
{
    void dig(std::vector<int> &vec, int current, int n)
    {
        // go through all figures
        for (int i = 0; i <= 9; i++)
        {
            int dug = current * 10 + i;
            //check if the next number is lower than the target
            if (dug <= n)
            {
                //add and dig deeper
                vec.push_back(dug);
                dig(vec, dug, n);
            }
            else
                return;
        }
    }

public:
    std::vector<int> lexicalOrder(int n) 
    {
        std::vector<int> result;
        //base case from [0; 9] or [0; n]
        for (int i = 1; i <= n && i < 10; i++)
        {
            result.push_back(i);

            //dig deeper before next base number
            dig(result, i, n);
        }
        
        return result;
    }
};
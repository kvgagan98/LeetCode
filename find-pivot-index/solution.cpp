#include <iostream>
#include <vector>

class Solution
{
    public:
        int pivotIndex(std::vector<int>& nums)
        {
           int i = 0;
           int length = nums.size();
           int runningLeftSum = 0;
           int runningRightSum = 0;
           int index = -1;
           
           for (i = 0; i < length; i++)
           {
                if (i > 0)
                {
                    runningRightSum += nums[i];
                }
           }

           for (i = 0; i < length; i++)
           {
               if (i > 0)
               {
                    runningLeftSum += nums[i - 1];
                    runningRightSum -= nums[i];
               }
               if (runningLeftSum == runningRightSum)
               {
                   index = i;
                   break;
               }
           }
           return index;
        }
};

int main ()
{
    Solution mySolution;
    std::vector<int> nums {1,7,3,6,5,6};
    int pivotIndex;
    pivotIndex = mySolution.pivotIndex(nums);
    std::cout << "pivotIndex = " << pivotIndex << std::endl;
    
    return 0;
}

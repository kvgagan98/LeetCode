#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies)
    {
        int i {};
        int vecLen = candies.size();
        std::vector<bool> result (vecLen);
        int currCandies {};
        int maxCandies {};

        maxCandies = candies.at(i);
        for (i = 1; i < vecLen; i++)
        {
            if (candies.at(i) > maxCandies)
            {
                maxCandies = candies.at(i);
            }
        }

        for (i = 0; i < vecLen; i++)
        {
            currCandies = candies.at(i) + extraCandies;
            if (currCandies >= maxCandies)
            {
                result.at(i) = true;
            }
        }
        return result;
    }
};

int main () {
    Solution mySol;
    std::vector<int> candies {2,3,5,1,3};
    std::vector<bool> result (candies.size());
    result = mySol.kidsWithCandies(candies, 3);

    std::cout << "Result = " << result.at(0) << std::endl;

    return 0;
}

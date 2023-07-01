#include <cmath>
#include <iostream>
#include <vector>

class Solution
{
    public:
        int largestAltitude(std::vector<int>& gain)
        {
            int n = gain.size();
            std::vector<int> altitudes (n+1);
            int maxAlt = 0;
            int i = 0;
            int j = 0;
            if (n == 0)
            {
                maxAlt = 0;
            }
            else 
            {
               altitudes.at(0) = 0;
               for (i = 1, j = 0; (i < (n+1)), j < n; i++, j++)
               {
                   altitudes.at(i) = altitudes.at(i - 1) + gain.at(j);
               }
               maxAlt = altitudes.at(0);
               for (i = 0; i < (n+1); i++)
               {
                    if (altitudes.at(i) > maxAlt)
                    {
                        maxAlt = altitudes.at(i);
                    }
               }
            }

            return maxAlt;
        }
};

int main () 
{
    Solution mySol;
    std::vector<int> gain {-5,1,5,0,-7};
    int altitude = mySol.largestAltitude(gain);

    std::cout << "Altitude = " << altitude << std::endl;
    return 0;
}

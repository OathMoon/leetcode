/*
 * @Author: OathMoon 
 * @Date: 2018-05-11 23:14:22 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-11 23:16:13
 */

#include <iostream>
#include <vector>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums)
{
    int max = 0;
    int count = 0;
    
    for (auto num : nums)
    {
        if (num)
        {
            count++;
            if (max < count)
            {
                max = count;
            }
        }
        else
        {
            count = 0;
        }
    }
    
    return max;
}

int main()
{
    vector<int> nums {1,1,0,1,1,1};
    
    cout << findMaxConsecutiveOnes(nums) << endl;

    return 0;
}
/*
 * @Author: OathMoon 
 * @Date: 2018-05-11 22:58:03 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-11 23:00:27
 */

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int result = 0;
    for (auto num : nums)
    {
        result ^= num;
    }
    
    return result;
}

int main()
{
    vector<int> nums {4,1,2,1,2};

    cout << singleNumber(nums) << endl;
}
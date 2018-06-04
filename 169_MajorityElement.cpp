/*
 * @Author: OathMoon 
 * @Date: 2018-06-05 00:19:52 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-06-05 00:24:44
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums)
{
    unordered_map<int, int> countMap;
    int n = nums.size();

    for (auto& num : nums)
    {
        if (++countMap[num] > n / 2)
        {
            return num;
        }
    }
}

int main()
{
    vector<int> nums {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;

    return 0;
}
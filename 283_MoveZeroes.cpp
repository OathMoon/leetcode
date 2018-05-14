/*
 * @Author: OathMoon 
 * @Date: 2018-05-14 22:57:00 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-14 22:58:28
 */

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums)
{
    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main()
{
    vector<int> nums {0,1,0,3,12};

    moveZeroes(nums);
    for (auto num : nums)
    {
        cout << num << "    ";
    }
    cout << endl;
}
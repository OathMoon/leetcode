/*
 * @Author: OathMoon 
 * @Date: 2018-05-14 23:05:51 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-14 23:33:27
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    vector<int> result;
    int i = 0;
    
    while (i < nums.size())
    {
        if (nums[nums[i] - 1] != nums[i])
        {
            swap(nums[nums[i] - 1], nums[i]);
        } else
        {
            ++i;
        }
    }
    
    for (int j = 0; j < nums.size(); ++j)
    {
        if (nums[j] != j + 1)
        {
            result.push_back(j + 1);
        }
    }
    
    return result;
}

int main()
{
    vector<int> nums {4,3,2,7,8,2,3,1};

    auto result = findDisappearedNumbers(nums);
    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;

    return 0;
}
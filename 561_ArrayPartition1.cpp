/*
 * @Author: OathMoon 
 * @Date: 2018-05-05 18:47:13 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-05 18:54:43
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int arrayPairSum1(vector<int>& nums)
{
    vector<int> hashtable(20001, 0);
    for (const auto i : nums)
        hashtable[i + 10000]++;
    
    int sum = 0;
    int i = 0;
    bool flag = true;
    while (i < 20001) {
        if (hashtable[i] > 0) {
            if (flag) {
                sum += (i - 10000);
                flag = false;
            } else {
                flag = true;
            }
            hashtable[i]--;
        } else {
            i++;
        }
    }
    
    return sum;
}

int arrayPairSum2(vector<int>& nums)
{
    int sum = 0;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i+=2) {
        sum += nums[i];
    }

    return sum;
}

int main()
{
    vector<int> nums {1, 4, 3, 2};

    cout << arrayPairSum1(nums) << endl;
    cout << arrayPairSum2(nums) << endl;
}
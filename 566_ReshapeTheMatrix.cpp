/*
 * @Author: OathMoon 
 * @Date: 2018-05-10 15:09:06 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-10 15:16:09
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
{
    int m = nums.size();
    int n = nums[0].size();
    
    if ((m*n) != r*c)
        return nums;
    
    vector<vector<int>> result(r, vector<int>(c, 0));
    
    for (int i = 0; i < r*c; i++)
    {
        result[i/c][i%c] = nums[i/n][i%n];
    }
    
    return result;
}

int main()
{
    vector<vector<int>> nums {{1,2},{3,4}};

    auto result = matrixReshape(nums, 1, 4);
    for (auto row : result)
    {
        for (auto num : row)
        {
            cout << num << "    ";
        }
        cout << endl;
    }

    return 0;
}
/*
 * @Author: OathMoon 
 * @Date: 2018-06-05 00:26:26 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-06-05 00:30:50
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> constructRectangle(int area)
{
    vector<int> result;
    int n = sqrt(area);

    for (int i = n; i > 0; --i)
    {
        if (area % i == 0)
        {
            int j = area / i;
            result = {max(i, j), min(i, j)};
            return result;
        }
    }
}

int main()
{
    vector<int> result = constructRectangle(4);
    
    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;

    return 0;
}
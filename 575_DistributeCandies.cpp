/*
 * @Author: OathMoon 
 * @Date: 2018-05-07 23:10:33 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-07 23:15:30
 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int distributeCandies(vector<int>& candies)
{
    bitset<200001> hash;

    for (auto i : candies)
    {
        if (!hash.test(i+100000))
        {
            hash.set(i+100000);
        }
    }
    
    return min(candies.size()/2, hash.count());
}

int main()
{
    vector<int> candies {1,1,2,3};

    cout << distributeCandies(candies) << endl;

    return 0;
}
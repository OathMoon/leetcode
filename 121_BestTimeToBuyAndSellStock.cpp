/*
 * @Author: OathMoon 
 * @Date: 2018-08-05 23:57:58 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-08-05 23:59:31
 */

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{        
    if (prices.size() < 2)
        return 0;
    
    int profit = prices[1] - prices[0];
    int minPrice = prices[0];
    for (int i = 2; i < prices.size(); ++i)
    {
        minPrice = min(minPrice, prices[i - 1]);
        if (profit < prices[i] - minPrice)
        {
            profit = prices[i] - minPrice;
        }
    }
    
    return profit < 0 ? 0 : profit;
}

int main()
{
    vector<int> prices {7,1,5,3,6,4};
    
    cout << maxProfit(prices) << endl;
}
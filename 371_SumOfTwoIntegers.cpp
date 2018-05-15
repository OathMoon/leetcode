/*
 * @Author: OathMoon 
 * @Date: 2018-05-15 23:14:55 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-15 23:19:44
 */

#include <iostream>

using namespace std;

int getSum(int a, int b)
{
    int sum = 0;
    int carry = 1;
    
    while (carry)
    {
        sum = a^b;
        carry = (a&b) << 1;
        
        a = sum;
        b = carry;
    }
    
    return sum;
}

int main()
{
    cout << getSum(1, 2) << endl;
    
    return 0;
}
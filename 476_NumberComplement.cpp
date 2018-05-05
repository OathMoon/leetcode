/*
 * @Author: OathMoon 
 * @Date: 2018-05-05 23:10:59 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-05 23:12:55
 */

#include <iostream>

using namespace std;

int findComplement(int num)
{
    int mask = ~0;
    while (num & mask)
    {
        mask <<= 1;
    }
    
    return ~mask ^ num;
}

int main()
{
    cout << findComplement(5) << endl;
}
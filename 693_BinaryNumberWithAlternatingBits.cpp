/*
 * @Author: OathMoon 
 * @Date: 2018-05-11 23:03:25 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-11 23:16:57
 */

#include <iostream>

using namespace std;

bool hasAlternatingBits(int n)
{
    n += (n >> 1) + 1;
    return !(n & (n-1));
}

int main()
{
    cout << boolalpha << hasAlternatingBits(10) << endl;

    return 0;
}
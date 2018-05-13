/*
 * @Author: OathMoon 
 * @Date: 2018-05-13 22:51:44 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-13 22:52:29
 */

#include <iostream>

using namespace std;

int addDigits(int num)
{
    return ((num - 1) % 9) + 1;
}

int main()
{
    cout << addDigits(38) << endl;

    return 0;
}
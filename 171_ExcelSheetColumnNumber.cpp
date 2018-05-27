/*
 * @Author: OathMoon 
 * @Date: 2018-05-27 22:56:26 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-27 22:57:34
 */

#include <iostream>
#include <string>

using namespace std;

int titleToNumber(string s)
{
    int colnum = 0;
    for (auto ch : s)
    {
        colnum *= 26;
        colnum += ch - 'A' + 1;
    }
    
    return colnum;
}

int main()
{
    cout << titleToNumber("ZY") << endl;

    return 0;
}
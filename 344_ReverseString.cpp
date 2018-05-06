/*
 * @Author: OathMoon 
 * @Date: 2018-05-06 23:56:52 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-06 23:57:47
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseString(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    cout << reverseString("hello") << endl;

    return 0;
}
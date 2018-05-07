/*
 * @Author: OathMoon 
 * @Date: 2018-05-07 22:47:13 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-07 23:11:35
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string reverseWords(string s)
{
    int cursor = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i] == ' ' || i == s.size())
        {
            reverse(s.begin()+cursor, s.begin()+i);
            ++i;
            cursor = i;
        }
    }

    return s;
}

int main()
{
    cout << reverseWords("Let's take LeetCode contest") << endl;

    return 0;
}
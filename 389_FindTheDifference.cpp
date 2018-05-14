/*
 * @Author: OathMoon 
 * @Date: 2018-05-14 22:59:38 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-14 23:01:47
 */

#include <iostream>
#include <string>

using namespace std;

char findTheDifference(string s, string t)
{
    char result = 0;
    
    for (auto ch : s)
    {
        result ^= ch;
    }
    
    for (auto ch : t)
    {
        result ^= ch;
    }
    
    return result;
}

int main()
{
    cout << findTheDifference("abcd", "aebdc") << endl;

    return 0;
}
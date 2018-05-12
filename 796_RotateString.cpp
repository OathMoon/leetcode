/*
 * @Author: OathMoon 
 * @Date: 2018-05-12 22:42:08 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-12 22:43:31
 */

#include <iostream>

using namespace std;

bool rotateString(string A, string B)
{
    return A.size() == B.size() && (A + A).find(B) != string::npos;
}

int main()
{
    cout << boolalpha << rotateString("abcde", "cdeab") << endl;
}
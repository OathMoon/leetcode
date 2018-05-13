/*
 * @Author: OathMoon 
 * @Date: 2018-05-13 22:48:49 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-13 22:50:38
 */

#include <iostream>
#include <string>

using namespace std;

bool detectCapitalUse(string word)
{
    int count = 0;
    
    for (auto ch : word)
    {
        if (isupper(ch))
        {
            count++;
        }
    }
    
    return (count == word.size()) || (count == 0) || (count == 1 && isupper(word[0]));
}

int main()
{
    string word = "Google";

    cout << boolalpha << detectCapitalUse(word) << endl;

    return 0;
}
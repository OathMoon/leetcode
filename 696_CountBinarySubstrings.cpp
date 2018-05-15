/*
 * @Author: OathMoon 
 * @Date: 2018-05-15 23:18:46 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-15 23:26:13
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countBinarySubstrings(string s)
{
    vector<int> counts;
    int count = 1;
    int result = 0;
    
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i-1] == s[i])
        {
            count++;
        }
        else
        {
            counts.push_back(count);
            count = 1;
        }
    }
    counts.push_back(count);
    
    for (int i = 1; i < counts.size(); i++)
    {
        result += min(counts[i-1], counts[i]);
    }
    
    return result;
}

int main()
{
    cout << countBinarySubstrings("00110011") << endl;

    return 0;
}
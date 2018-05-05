/*
 * @Author: OathMoon 
 * @Date: 2018-05-05 22:49:17 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-05 23:08:31
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> shortestToChar(string S, char C)
{
    int size = S.size();
    int currentPos = -size;
    vector<int> result(size, size);
    
    for (int i = 0; i < size; ++i)
    {
        if (S[i] == C)
        {
            currentPos = i;
        }
        
        result[i] = min(abs(i - currentPos), result[i]);
    }
    
    for (int i = size - 1; i >= 0; --i)
    {
        if (S[i] == C)
        {
            currentPos = i;
        }
        
        result[i] = min(abs(currentPos - i), result[i]);
    }

    return result;                    
}

int main()
{
    string S = "loveleetcode";
    char C = 'e';

    vector<int> result = shortestToChar(S, C);
    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;

    return 0;
}
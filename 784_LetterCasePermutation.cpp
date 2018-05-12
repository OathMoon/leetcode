/*
 * @Author: OathMoon 
 * @Date: 2018-05-12 22:29:31 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-12 22:40:15
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<string> letterCasePermutation(string S)
{
    deque<string> stringQueue;
    
    stringQueue.push_back(S);
    for (int i = 0; i < S.size(); ++i)
    {
        if (isalpha(S[i]))
        {
            int size = stringQueue.size();
            for (int j = 0; j < size; ++j)
            {
                string cur = stringQueue.front();
                stringQueue.pop_front();
                
                cur[i] = toupper(cur[i]);
                stringQueue.push_back(cur);
                
                cur[i] = tolower(cur[i]);
                stringQueue.push_back(cur);
            }
        }
    }
    
    vector<string> result(stringQueue.begin(), stringQueue.end());
    
    return result;
}

int main()
{
    vector<string> result = letterCasePermutation("a1b2");
    for (auto str : result)
    {
        cout << str << "    ";
    }
    cout << endl;

    return 0;
}
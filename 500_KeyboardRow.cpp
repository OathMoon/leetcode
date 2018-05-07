/*
 * @Author: OathMoon 
 * @Date: 2018-05-07 23:04:17 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-07 23:11:40
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findWords(vector<string>& words)
{
    vector<string> result;
    unordered_map<char, int> rowmap;
    
    for (auto word : "qwertyuiop")
    {
        rowmap[word] = 1;
    }
    
    for (auto word : "asdfghjkl")
    {
        rowmap[word] = 2;
    }
    
    for (auto word : "zxcvbnm")
    {
        rowmap[word] = 3;
    }
    
    for (auto word : words)
    {
        int row = rowmap[tolower(word[0])];
        bool samerow = true;
        for (auto ch : word)
        {
            if (rowmap[tolower(ch)] != row)
            {
                samerow = false;
                break;
            }
        }
        
        if (samerow)
        {
            result.push_back(word);
        }
    }
    
    return result;
}

int main()
{
    vector<string> words {"Hello", "Alaska", "Dad", "Peace"};

    vector<string> result = findWords(words);
    for (auto str : result)
    {
        cout << str << "    ";
    }
    cout << endl;

    return 0;
}
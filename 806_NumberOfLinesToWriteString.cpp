/*
 * @Author: OathMoon 
 * @Date: 2018-05-05 22:25:46 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-05 22:29:33
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> numberOfLines(vector<int>& widths, string S)
{       
    int widthCount = 0;
    int lineCount = 0;
    
    for (auto ch : S)
    {
        int currentWidth = widths[ch - 'a'];
        if (widthCount + currentWidth > 100)
        {
            lineCount++;
            widthCount = currentWidth;
        }
        else
        {
            widthCount += currentWidth;
        }
    }
    
    lineCount++;
    
    return vector<int>{lineCount, widthCount};
}

int main()
{
    vector<int> widths {4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    string S = "bbbcccdddaaa";

    vector<int> result = numberOfLines(widths, S);
    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;

    return 0;
}
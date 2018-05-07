/*
 * @Author: OathMoon 
 * @Date: 2018-05-07 23:32:50 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-07 23:37:51
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int calPoints(vector<string>& ops)
{
    vector<int> roundPoints;
    int sum = 0;
    int score = 0;
    for (auto s : ops)
    {
        switch(s[0])
        {
            case 'D':
            {
                score = roundPoints.back() * 2;
                sum += score;
                roundPoints.push_back(score);
                break;
            }
            case '+':
            {
                score = roundPoints[roundPoints.size()-1] + roundPoints[roundPoints.size()-2];
                roundPoints.push_back(score);
                sum += score;
                break;
            }
            case 'C':
            {
                sum -= roundPoints.back();
                roundPoints.pop_back();
                break;
            }
            default:
            {
                score = stoi(s);
                sum += score;
                roundPoints.push_back(score);
            }
        }
    }
    
    return sum;
}

int main()
{
    vector<string> ops {"5","-2","4","C","D","9","+","+"};

    cout << calPoints(ops) << endl;

    return 0;
}
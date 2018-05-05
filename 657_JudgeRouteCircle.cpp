/*
 * @Author: OathMoon 
 * @Date: 2018-05-04 23:15:23 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-04 23:34:15
 */

#include <iostream>
#include <string>

using namespace std;

bool judgeCircle(string moves)
{
    int x = 0, y = 0;
    for (int i = 0; i < moves.size(); i++)
    {
        switch (moves[i])
        {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
        }
    }
    
    if (x==0 && y==0)
        return true;
    return false;
}

int main()
{
    cout << boolalpha << judgeCircle("UD") << endl;
}
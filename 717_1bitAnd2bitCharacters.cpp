/*
 * @Author: OathMoon 
 * @Date: 2018-05-17 22:43:11 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-17 22:45:49
 */

#include <iostream>
#include <vector>

using namespace std;

bool isOneBitCharacter1(vector<int>& bits)
{
    int i = 0;
    int n = bits.size();
    
    while (i < n - 1)
    {
        if (bits[i] == 1)
        {
            i += 2;
        }
        else
        {
            i++;
        }
    }
    
    return i == (n - 1);
}

bool isOneBitCharacter2(vector<int>& bits)
{
    int count = 0;
    int n = bits.size();
    
    if (bits[n-2] == 0)
    {
        return true;
    }
    
    for (int i = n-2; i >= 0 && bits[i] == 1; i--)
    {
        count++;
    }
    
    return !(count % 2);
}

int main()
{
    vector<int> bits {1, 1, 1, 0};

    cout << boolalpha << isOneBitCharacter1(bits) << endl;
    cout << boolalpha << isOneBitCharacter2(bits) << endl;

    return 0;
}
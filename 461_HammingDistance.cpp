/*
 * @Author: OathMoon 
 * @Date: 2018-05-02 18:45:57 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-02 18:47:10
 */

#include <iostream>

using namespace std;

int hammingDistance(int x, int y)
{
    int n = x^y;
    int count = 0;
    while (n)
    {
        n = n&(n-1);
        count++;
    }
    return count;
}

int main()
{
    cout << hammingDistance(1, 4) << endl;

    return 0;
}
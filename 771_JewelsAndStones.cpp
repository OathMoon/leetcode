/*
 * @Author: OathMoon 
 * @Date: 2018-05-02 18:11:04 
 * @Last Modified by:   OathMoon 
 * @Last Modified time: 2018-05-02 18:11:04 
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int numJewelsInStones(string J, string S)
{
    unordered_set<char> jewelsSet(J.cbegin(), J.cend());
    int count = 0;
    
    for (auto ch : S)
        if (jewelsSet.count(ch))
            count++;
    
    return count;
}

int main()
{
    string J = "aA", S = "aAAbbbb";
    cout << numJewelsInStones(J, S) << endl;

    return 0;
}
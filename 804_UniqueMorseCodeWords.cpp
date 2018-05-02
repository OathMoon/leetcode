/*
 * @Author: OathMoon 
 * @Date: 2018-05-02 18:11:09 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-02 18:13:25
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words)
{
    int result = 0;
    unordered_set<string> hashset;
    vector<string> morseString = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    for (auto str : words)
    {
        string morse = "";
        for (auto ch : str)
        {
            morse += morseString[ch - 97];
        }
        hashset.insert(morse);
    }
    
    return hashset.size();
}

int main()
{
    vector<string> words = {"gin", "zen", "gig", "msg"};
    cout << uniqueMorseRepresentations(words) << endl;

    return 0;
}
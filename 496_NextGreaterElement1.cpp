/*
 * @Author: OathMoon 
 * @Date: 2018-05-10 15:18:15 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-10 15:21:11
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
{
    vector<int> result;
    stack<int> st;
    unordered_map<int, int> hashmap;
    
    for (auto number : nums)
    {
        while (!st.empty() && st.top() < number)
        {
            hashmap[st.top()] = number;
            st.pop();
        }
        st.push(number);
    }
    
    for (auto number : findNums)
    {
        result.push_back(hashmap[number] ? hashmap[number] : -1);
    }
    
    return result;
}

int main()
{
    vector<int> findNums {4,1,2};
    vector<int> nums {1,3,4,2};

    auto result = nextGreaterElement(findNums, nums);
    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;

    return 0;
}
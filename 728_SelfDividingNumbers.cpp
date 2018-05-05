/*
 * @Author: OathMoon 
 * @Date: 2018-05-05 18:41:18 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-05 18:45:00
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> result;
    for (int i = left; i <= right; i++) {
        int msbNumber = i;
        bool isDividingNumber = true;
        while (msbNumber > 0)
        {
            int divideNumber = msbNumber % 10;
            if ((divideNumber == 0) || (i % divideNumber != 0)) {
                isDividingNumber = false;
                break;
            }

            msbNumber = msbNumber / 10;
        }

        if (isDividingNumber)
        {
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    vector<int> result = selfDividingNumbers(1, 22);

    for (auto num : result)
    {
        cout << num << "    ";
    }
    cout << endl;
}
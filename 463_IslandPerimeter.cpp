/*
 * @Author: OathMoon 
 * @Date: 2018-05-10 14:54:01 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-10 15:00:56
 */

#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid)
{
    int lands = 0;
    int repeat = 0;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                lands++;
                if ((j != grid[0].size()-1) && (grid[i][j+1] == 1))
                    repeat++;
                if((i != grid.size()-1) && (grid[i+1][j] == 1))
                    repeat++;
            }
        }
    }

    return 4*lands - 2*repeat;
}

int main()
{
    vector<vector<int>> grid {{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};

    cout << islandPerimeter(grid) << endl;

    return 0;
}
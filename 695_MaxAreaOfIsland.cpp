/*
 * @Author: OathMoon 
 * @Date: 2018-05-13 23:00:25 
 * @Last Modified by: OathMoon
 * @Last Modified time: 2018-05-13 23:05:34
 */

#include <iostream>
#include <vector>

using namespace std;

int getCurrentArea(vector<vector<int>>& grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
    {
        return 0;
    }

    grid[i][j] = 0;
    int area = 1 + getCurrentArea(grid, i-1, j) + getCurrentArea(grid, i, j-1) + getCurrentArea(grid, i+1, j) + getCurrentArea(grid, i, j+1);
    
    return area;
}

int maxAreaOfIsland(vector<vector<int>>& grid)
{
    int maxarea = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                int area = getCurrentArea(grid, i, j);
                maxarea = max(area, maxarea);
            }
        }
    }
    
    return maxarea;
}

int main()
{
    return 0;
}
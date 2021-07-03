#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int DFS(vector<vector<int>> &grid, int i, int j, int &count)
    {
        // boundary checking
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return count;
        // return if current position is of water or is already visited
        if (grid[i][j] == 2 || grid[i][j] == 0)
            return count;

        // mark the current as visited
        grid[i][j] = 2;
        count++;

        // do DFS in all 4 directions
        DFS(grid, i + 1, j, count);
        DFS(grid, i, j - 1, count);
        DFS(grid, i - 1, j, count);
        DFS(grid, i, j + 1, count);
        return count;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int islands = 0;
        int ans = 0;
        int count;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    count = 0;
                    int res = DFS(grid, i, j, count);
                    ans = max(ans, res);
                    islands++;
                }
            }
        }
        if (islands == 0)
            return 0;
        return ans;
    }
};
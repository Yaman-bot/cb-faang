#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        //row,col,depth
        queue<pair<pair<int, int>, int>> q;
        int depth = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push({{i, j}, depth});
            }
        }

        int ans = 0;
        int rowIndex[] = {0, 0, -1, 1}; //right,left,up,down
        int colIndex[] = {1, -1, 0, 0};
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            int row = x.first.first;
            int col = x.first.second;
            int currDepth = x.second;
            ans = max(ans, currDepth);
            for (int i = 0; i < 4; i++)
            {
                int rowPos = row + rowIndex[i];
                int colPos = col + colIndex[i];
                if (rowPos >= 0 && rowPos < grid.size() && colPos >= 0 && colPos < grid[0].size() && grid[rowPos][colPos] == 1)
                {
                    grid[rowPos][colPos] = 2;
                    q.push({{rowPos, colPos}, currDepth + 1});
                }
            }
        }

        //If still a fresh orange is present
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return ans;
    }
};
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        // write your code here
        queue<pair<int, int>> q;
        vector<vector<int>> v;
        int rowSize = rooms.size();
        int colSize = rooms[0].size();
        if (rowSize == 0)
            return;

        vector<vector<bool>> visited;
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (rooms[i][j] == 0)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    v[i][j] = 0;
                }
                else
                {
                    v[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            //Down
            if (r + 1 < rowSize && !(visited[r + 1][c]) && rooms[r + 1][c] != -1)
            {
                v[r + 1][c] = v[r][c] + 1;
                q.push({r + 1, c});
                visited[r + 1][c] = true;
            }
            //Up
            if (r - 1 >= 0 && !(visited[r - 1][c]) && rooms[r - 1][c] != -1)
            {
                v[r - 1][c] = v[r][c] + 1;
                q.push({r - 1, c});
                visited[r - 1][c] = true;
            }
            //Right
            if (c + 1 < colSize && !(visited[r][c + 1]) && rooms[r][c + 1] != -1)
            {
                v[r][c + 1] = v[r][c] + 1;
                q.push({r, c + 1});
                visited[r][c + 1] = true;
            }
            //Left
            if (c - 1 >= 0 && !(visited[r][c]) && rooms[r][c - 1] != -1)
            {
                v[r][c - 1] = v[r][c] + 1;
                q.push({r, c - 1});
                visited[r][c - 1] = true;
            }
        }

        for (int i = 0; i < rowSize; i++)
        {
            for (int j = 0; j < colSize; j++)
            {
                if (rooms[i][j] > 0)
                {
                    if (v[i][j] = -1)
                    {
                        v[i][j] = 2147483647;
                    }
                    rooms[i][j] = v[i][j];
                }
            }
        }
    }
};
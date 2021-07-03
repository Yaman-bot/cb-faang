#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool dfs(int color[], vector<int> graph[], int node)
    {
        if (color[node] == -1)
            color[node] = 1;

        for (auto it : graph[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!dfs(color, graph, it))
                    return false;
            }
            else if (color[it] == color[node])
                return false;
        }
        return true;
    }

    bool bfs(int color[], vector<int> graph[], int node)
    {
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (auto nbr : graph[temp])
            {
                if (color[nbr] == -1)
                {
                    color[nbr] = 1 - color[temp];
                    q.push(nbr);
                }
                else if (color[nbr] == color[temp])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<int> graph[], int n)
    {
        int color[100];
        memset(color, -1, sizeof(color));
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1 && !dfs(color, graph, i))
            {
                return false;
            }
        }
        return true;
    }
};
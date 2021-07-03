#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> l;

public:
    void addEdge(int x, int y)
    {
        l[x].push_back(y);
    }

    void dfs_helper(T src, map<T, bool> &visited)
    {
        visited[src] = true;
        for (auto nbr : l[src])
        {
            if (!visited[nbr])
                dfs_helper(nbr, visited);
        }
    }

    int dfs(T src)
    {
        map<T, bool> visited;
        for (auto p : l)
        {
            T node = p.first;
            visited[node] = false;
        }

        int count = 0;
        for (auto p : l)
        {
            T node = p.first;
            if (!visited[node])
            {
                count++;
                dfs_helper(node, visited);
            }
        }
        return count;
    }
};

class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        Graph<int> g;
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected[0].size(); j++)
            {
                if (isConnected[i][j] == 1)
                    g.addEdge(i, j);
            }
        }
        int ans = g.dfs(0);
        return ans;
    }
};
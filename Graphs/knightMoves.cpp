#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <list>
using namespace std;

class Graph
{
    map<pair<int, int>, list<pair<int, int>>> m;

public:
    void addEdge(int i, int j, int N)
    {
        pair<int, int> p = make_pair(i, j);
        if (i + 2 < N)
        {
            if (j + 1 < N)
                m[p].push_back({i + 2, j + 1});
            if (j - 1 >= 0)
                m[p].push_back({i + 2, j - 1});
        }
        if (i - 2 >= 0)
        {
            if (j + 1 < N)
                m[p].push_back({i - 2, j + 1});
            if (j - 1 >= 0)
                m[p].push_back({i - 2, j - 1});
        }
        if (i + 1 < N)
        {
            if (j + 2 < N)
                m[p].push_back({i + 1, j + 2});
            if (j - 2 >= 0)
                m[p].push_back({i + 1, j - 2});
        }
        if (i - 1 >= 0)
        {
            if (j + 2 < N)
                m[p].push_back({i - 1, j + 2});
            if (j - 2 >= 0)
                m[p].push_back({i - 1, j - 2});
        }
    }

    int BFS(int s1, int s2, int d1, int d2, int N)
    {
        pair<int, int> src = make_pair(s1, s2);
        pair<int, int> dest = make_pair(d1, d2);
        map<pair<int, int>, int> dist;
        queue<pair<int, int>> q;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                dist[{i, j}] = INT_MAX;
            }
        }

        q.push(src);
        dist[src] = 0;

        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            for (auto nbr : m[p])
            {
                if (dist[nbr] == INT_MAX)
                {
                    dist[nbr] = dist[p] + 1;
                    q.push(nbr);
                }
            }
        }

        int distance = dist[dest];
        if (distance == INT_MAX)
            distance = 1;
        return distance;
    }
};

class Solution
{
public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        // Code here
        Graph g;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                g.addEdge(i, j, N);
            }
        }
        int ans = g.BFS(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], N);
        return ans;
    }
};
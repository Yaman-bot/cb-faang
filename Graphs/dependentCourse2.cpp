#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, list<int>> graph;

        for (auto x : prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        vector<int> x;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto nbr : graph[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        if (ans.size() == numCourses)
            return ans;
        else
            return x;
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<int> zeros;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
                zeros.push_back(i);
        }

        unordered_map<int, list<int>> m;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == 0)
                continue;
            else
            {
                if (i + arr[i] < arr.size())
                    m[i].push_back(i + arr[i]);
                if (i - arr[i] >= 0)
                    m[i].push_back(i - arr[i]);
            }
        }

        unordered_map<int, bool> visited;
        for (int i = 0; i < arr.size(); i++)
            visited[i] = false;

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int nbr : m[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        for (int i = 0; i < zeros.size(); i++)
        {
            if (visited[zeros[i]])
                return true;
        }
        return false;
    }
};
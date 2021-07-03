#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Solution
{
public:
    /**
     * @param pid: the process id
     * @param ppid: the parent process id
     * @param kill: a PID you want to kill
     * @return: a list of PIDs of processes that will be killed in the end
     */
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
    {
        unordered_map<int, list<int>> m;
        vector<int> ans;

        for (int i = 0; i < pid.size(); i++)
            m[ppid[i]].push_back(pid[i]);

        queue<int> q;
        q.push(kill);
        ans.push_back(kill);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int child : m[node])
            {
                ans.push_back(child);
                q.push(child);
            }
        }
        return ans;
    }
};
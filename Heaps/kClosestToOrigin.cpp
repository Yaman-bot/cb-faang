#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Time complexity=O(N*logK )
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (pq.size() < k || dist < pq.top())
            {
                if (pq.size() == k)
                {
                    pq.pop();
                }
                pq.push(dist);
            }
        }

        int num = pq.top();
        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (dist < num)
            {
                i++;
            }
            else
            {
                swap(points[i], points[j]);
                j--;
            }
        }
        points.erase(points.begin() + k, points.end());
        return points;
    }
};
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        int cs = 0;
        while (cs < k)
        {
            pq.push(nums[cs]);
            cs++;
        }

        for (int i = cs; i < nums.size(); i++)
        {
            if (nums[i] > pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};
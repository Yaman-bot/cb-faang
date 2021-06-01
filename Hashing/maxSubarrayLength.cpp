#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxSubarrayLen(vector<int> &nums, int k)
{
    vector<int> prefixSum;
    unordered_map<int, int> m;
    int sum = 0;
    prefixSum.push_back(0);

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        prefixSum.push_back(sum);
    }

    for (int i = 0; i < prefixSum.size(); i++)
    {
        m[prefixSum[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < prefixSum.size(); i++)
    {
        if (m.find(k + prefixSum[i]) != m.end())
        {
            int index = m[k + prefixSum[i]];
            if (index - i > ans)
            {
                ans = index - i;
            }
        }
    }
    return ans;
}
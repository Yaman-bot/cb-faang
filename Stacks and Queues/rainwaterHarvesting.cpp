#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        int ans = 0;

        int leftMax[n];
        int rightMax[n];
        leftMax[0] = 0;
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }
        rightMax[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }

        for (int i = 0; i < n; i++)
        {
            int level = min(leftMax[i], rightMax[i]);
            if (level - height[i] > 0)
            {
                ans += level - height[i];
            }
        }
        return ans;
    }
};
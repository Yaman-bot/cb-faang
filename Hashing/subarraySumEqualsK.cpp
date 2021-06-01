#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int cum = 0;
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cum += nums[i];
            if (cum == k)
            {
                cnt++;
            }
            if (mp.find(cum - k) != mp.end())
                cnt += mp[cum - k];
            mp[cum]++;
        }
        return cnt;
    }
};
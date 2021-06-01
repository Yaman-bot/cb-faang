#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }

        vector<vector<int>> freq(nums.size() + 1);

        for (auto key : m)
        {
            freq[key.second].push_back(key.first);
        }

        vector<int> ans;
        for (int i = freq.size() - 1; i >= 0 && ans.size() < k; i--)
        {
            for (int num : freq[i])
            {
                ans.push_back(num);
                if (ans.size() == k)
                    break;
            }
        }
        return ans;
    }
};
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        unordered_map<int, list<int>> m;
        if (nums.size() == 1)
            return 1;
        int res = 2;

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int d = nums[j] - nums[i];
                int num = nums[j] + d;
                int count = 2;
                int pos = j;
                while (m.find(num) != m.end())
                {
                    bool flag = false;
                    for (auto node : m[num])
                    {
                        if (node > pos)
                        {
                            count++;
                            num += d;
                            pos = node;
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                    {
                        break;
                    }
                }
                res = max(res, count);
            }
        }
        return res;
    }
};
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (string str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto key : m)
        {
            ans.push_back(key.second);
        }
        return ans;
    }
};
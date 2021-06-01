#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> m;
        int ans = 0;
        int j = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if (m.find(ch) != m.end())
            {
                j = max(j, m[ch] + 1);
            }
            m[ch] = i;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
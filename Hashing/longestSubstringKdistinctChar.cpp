#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k)
    {
        // write your code here
        if (s.length() * k == 0)
            return 0;
        unordered_map<char, int> m;
        int left = 0;
        int max_len = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            m[ch] = i;
            if (m.size() == k + 1)
            {
                char chMin = '0';
                int minIndex = INT_MAX;
                for (auto key : m)
                {
                    if (key.second < minIndex)
                    {
                        chMin = key.first;
                        minIndex = key.second;
                    }
                }
                left = minIndex + 1;
                m.erase(chMin);
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
    }
};
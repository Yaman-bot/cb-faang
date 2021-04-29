#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    struct comp
    {
        bool operator()(pair<int, string> a, pair<int, string> b)
        {
            if (a.first > b.first)
            {
                return 0;
            }
            if (a.first < b.first)
            {
                return 1;
            }
            return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++)
        {
            map[words[i]]++;
        }
        unordered_map<string, int>::iterator it;
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> p;
        for (it = map.begin(); it != map.end(); it++)
        {
            p.push({it->second, it->first});
        }
        vector<string> v;
        while (k > 0)
        {
            auto x = p.top();
            v.push_back(x.second);
            p.pop();
            k--;
        }
        return v;
    }
};
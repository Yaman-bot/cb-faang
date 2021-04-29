#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    string reorganizeString(string S)
    {
        string ans = "";
        int freq[26] = {0};
        for (int i = 0; i < S.length(); i++)
        {
            freq[S[i] - 'a']++;
        }

        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                pq.push({freq[i], char(i + 'a')});
            }
        }

        while (!pq.empty())
        {
            if (pq.size() >= 2)
            {
                pair<int, char> p1;
                pair<int, char> p2;

                p1 = pq.top();
                pq.pop();

                p2 = pq.top();
                pq.pop();

                ans += p1.second;
                ans += p2.second;

                p1.first--;
                p2.first--;

                if (p1.first)
                    pq.push(p1);
                if (p2.first)
                    pq.push(p2);
            }
            else if (pq.size() == 1)
            {
                if (pq.top().first > 1)
                {
                    return "";
                }
                else
                {
                    ans += pq.top().second;
                    pq.pop();
                }
            }
        }
        return ans;
    }
};
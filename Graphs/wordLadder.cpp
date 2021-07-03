#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s;
        bool found = false;
        for (auto word : wordList)
        {
            if (word == endWord)
            {
                found = true;
            }
            s.insert(word);
        }
        if (!found)
            return 0;
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while (!q.empty())
        {
            depth++;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string curr = q.front();
                q.pop();
                for (int i = 0; i < curr.size(); i++)
                {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        temp[i] = c;
                        if (temp == curr)
                        {
                            continue;
                        }
                        if (temp == endWord)
                        {
                            return depth + 1;
                        }
                        if (s.find(temp) != s.end())
                        {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
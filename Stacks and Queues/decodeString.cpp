#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<pair<string, int>> st;
        string temp = "";
        string ans = "";

        int i = 0;
        while (i < s.length())
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                int num = 0;
                while (isdigit(ch))
                {
                    int tempnum = ch - '0';
                    num = num * 10 + tempnum;
                    i++;
                }
                st.push(make_pair(temp, num));
                temp = "";
            }
            else if (isalpha(ch))
            {
                temp += ch;
            }
            else if (ch == ']')
            {
                pair<string, int> p = st.top();
                st.pop();
                string current = p.first;
                for (int j = 0; j < p.second; j++)
                {
                    current += temp;
                }

                if (st.empty())
                {
                    ans += current;
                    temp = "";
                }
                else
                {
                    temp = current;
                }
            }
            i++;
        }

        ans += temp;
        return ans;
    }
};
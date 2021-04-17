#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> s;
        int count = 0;

        for (int i = 0; num[i] != '\0'; i++)
        {
            while (!s.empty() && count < k && s.top() > num[i])
            {
                s.pop();
                count++;
            }
            s.push(num[i]);
        }

        string ans = "";
        while (count < k)
        {
            s.pop();
            count++;
        }

        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        count = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == '0')
            {
                count++;
            }
            else
            {
                break;
            }
        }

        ans = ans.substr(count, ans.size() - count);
        if (ans == "")
        {
            ans += "0";
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    cout << solution.removeKdigits("10200", 1) << endl;
}
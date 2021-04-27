#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int buySell(int *a, int n)
{
    stack<int> s;
    int maxProfit = 0;
    s.push(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (s.top() > a[i])
        {
            s.push(a[i]);
        }
        else
        {
            int p = a[i] - s.top();
            maxProfit = max(maxProfit, p);
        }
    }
    return maxProfit;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << buySell(a, n);
}
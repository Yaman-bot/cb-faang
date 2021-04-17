#include <iostream>
#include <deque>
#include <climits>
#include <algorithm>
using namespace std;

int SubArraySum(int *arr, int n, int k)
{
    int *prefixSum = new int[n + 1];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += arr[i];
        prefixSum[i] = x;
    }

    deque<pair<int, int>> q;
    q.push_back({0, -1});

    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && prefixSum[i] - q.front().first > k)
        {
            ans = min(ans, i - q.front().second);
            q.pop_front();
        }

        while (!q.empty() && q.back().first >= prefixSum[i])
        {
            q.pop_back();
        }

        q.push_back({prefixSum[i], i});
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    cout << SubArraySum(arr, n, k) << endl;
    return 0;
}
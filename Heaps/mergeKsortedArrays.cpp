#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKsortedArrays(vector<vector<int>> arr)
{
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq;

    int n = arr.size();

    //Insert 0th element in min heap
    for (int i = 0; i < n; i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }

    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();

        int ele = current.first;       //Element
        int x = current.second.first;  //Array index
        int y = current.second.second; //Element index

        result.push_back(ele);

        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}
#include <iostream>
#include <vector>
using namespace std;

bool minHeap = false;

bool compare(int a, int b)
{
    if (minHeap)
        return a < b;
    else
        return a > b;
}

void heapify(vector<int> &v, int idx, int size)
{
    int left = 2 * idx;
    int right = 2 * idx + 1;

    int last = size - 1;
    int min_idx = idx;

    if (left <= last && compare(v[left], v[idx]))
        min_idx = left;
    if (right <= last && compare(v[right], v[min_idx]))
        min_idx = right;

    if (min_idx != idx)
    {
        swap(v[idx], v[min_idx]);
        heapify(v, min_idx, size);
    }
}

void buildHeap(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i, v.size());
    }
}

void heapSort(vector<int> &v)
{
    buildHeap(v);
    int n = v.size();
    while (n > 1)
    {
        swap(v[1], v[n - 1]);
        n--;
        heapify(v, 1, n);
    }
}

int main()
{
    vector<int> v;
    v.push_back(-1);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        v.push_back(no);
    }

    heapSort(v);

    for (int i = 1; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

public:
    Heap(int defaultSize = 10, bool type = true)
    {
        v.reserve(defaultSize);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int data)
    {
        v.push_back(data);

        int idx = v.size() - 1;
        int parent = idx / 2;

        while (idx > 1 && compare(v[idx], v[parent]))
        {
            swap(v[idx], v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    bool isEmpty()
    {
        return v.size() == 1;
    }

    void pop()
    {
        int last = v.size() - 1;
        swap(v[last], v[1]);
        v.pop_back();
        heapify(1);
    }

    void heapify(int idx)
    {
        int left = 2 * idx;
        int right = 2 * idx + 1;

        int last = v.size() - 1;
        int min_idx = idx;

        if (left <= last && compare(v[left], v[idx]))
            min_idx = left;
        if (right <= last && compare(v[right], v[min_idx]))
            min_idx = right;

        if (min_idx != idx)
        {
            swap(v[idx], v[min_idx]);
            heapify(min_idx);
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Heap h;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }

    while (!h.isEmpty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}
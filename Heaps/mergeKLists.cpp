#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    struct compare
    {
        bool operator()(ListNode *root1, ListNode *root2)
        {
            return root1->val > root2->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, compare> pq;
        for (ListNode *node : lists)
        {
            if (node != NULL)
            {
                pq.push(node);
            }
        }

        if (pq.empty())
            return NULL;

        ListNode *node = new ListNode(-1);
        ListNode *curr = node;

        while (!pq.empty())
        {
            ListNode *temp = pq.top();
            pq.pop();
            curr->next = temp;
            curr = curr->next;

            if (temp->next)
                pq.push(temp->next);
        }

        return node->next;
    }
};
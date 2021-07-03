#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        queue<Node *> q;
        q.push(node);
        unordered_map<Node *, Node *> m;

        m[node] = new Node(node->val);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            Node *copy = m[temp];
            if (temp->neighbors.size() != 0)
            {
                vector<Node *> curr_neighbors = temp->neighbors;
                for (Node *nbr : curr_neighbors)
                {
                    Node *cloned = m[nbr];
                    if (cloned == NULL)
                    {
                        q.push(nbr);
                        cloned = new Node(nbr->val);
                        m[nbr] = cloned;
                    }
                    copy->neighbors.push_back(cloned);
                }
            }
        }
        return m[node];
    }
};
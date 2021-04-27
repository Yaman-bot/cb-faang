#include <iostream>
#include <queue>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (root == NULL)
            return NULL;
        if (depth == 1)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int currDepth = 1;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
                currDepth++;
            }
            else
            {
                if (currDepth == depth - 1)
                {
                    TreeNode *leftTemp = temp->left;
                    TreeNode *rightTemp = temp->right;
                    temp->left = new TreeNode(val);
                    temp->right = new TreeNode(val);
                    temp->left->left = leftTemp;
                    temp->right->right = rightTemp;
                }
                else
                {
                    if (temp->left)
                        q.push(temp->left);
                    if (temp->right)
                        q.push(temp->right);
                }
            }
        }
        return root;
    }
};
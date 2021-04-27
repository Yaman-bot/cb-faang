#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution
{
public:
    /*
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode *findLeftMost(TreeNode *root)
    {
        if (root == NULL)
            return NULL;
        TreeNode *left = findLeftMost(root->left);
        if (left == NULL)
            return NULL;
        return left;
    }

    TreeNode *inorderSuccessor(TreeNode *p)
    {
        TreeNode *parent = NULL;
        if (p->right)
        {
            return findLeftMost(p->right);
        }
        else
        {
            while (p->parent != NULL && p->parent->right == p)
            {
                p = p->parent;
            }
            return p->parent;
        }
    }
};
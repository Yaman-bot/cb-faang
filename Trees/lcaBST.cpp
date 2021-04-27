#include <iostream>
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return NULL;
        if (root->val == p->val || (root->val == q->val))
            return root;
        if ((p->val <= root->val && q->val > root->val) || (p->val > root->val && q->val <= root->val))
        {
            return root;
        }
        else if ((p->val <= root->val && q->val <= root->val))
        {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            return left;
        }
        else if ((p->val > root->val && q->val > root->val))
        {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            return right;
        }
        return root;
    }
};
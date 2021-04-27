#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    bool check = false;
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        // write your code here
        if (root == NULL)
            return NULL;
        TreeNode *left = inorderSuccessor(root->left, p);
        if (left)
            return left;
        if (check)
        {
            check = false;
            return root;
        }
        if (root->val == p->val)
            check = true;
        TreeNode *right = inorderSuccessor(root->right, p);
        if (right)
            return right;
        return NULL;
    }
};
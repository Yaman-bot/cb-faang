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
    /**
     * @param root: root of a tree
     * @return: head node of a doubly linked list
     */
    TreeNode *first = NULL;
    TreeNode *last = NULL;

    void helper(TreeNode *root)
    {
        if (root != NULL)
        {
            helper(root->left);
            if (last == NULL)
            {
                first = root;
            }
            else
            {
                root->left = last;
                last->right = root;
            }
            last = root;
            helper(root->right);
        }
    }

    TreeNode *treeToDoublyList(TreeNode *root)
    {
        // Write your code here.
        if (root == NULL)
            return NULL;

        helper(root);
        first->left = last;
        last->right = first;
        return first;
    }
};
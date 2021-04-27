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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        TreeNode *right = root->right;
        flatten(root->left);
        root->right = root->left;
        root->left = nullptr;
        TreeNode *temp1 = root;
        while (temp1->right != nullptr)
            temp1 = temp1->right;
        temp1->right = right;
        flatten(right);
    }
};
#include <iostream>
#include <vector>
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
    int max_level = 0;
    void rightView(TreeNode *root, int level, vector<int> &r)
    {
        if (root == NULL)
        {
            return;
        }
        if (level > max_level)
        {
            r.push_back(root->val);
            max_level = level;
        }
        rightView(root->right, level + 1, r);
        rightView(root->left, level + 1, r);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> r;
        int level = 1;
        rightView(root, level, r);
        return r;
    }
};
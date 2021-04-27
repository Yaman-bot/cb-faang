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
    void helper(TreeNode *root, int targetSum, int currSum, vector<int> currPath, vector<vector<int>> &res)
    {
        if (root == NULL)
            return;

        currSum += root->val;
        currPath.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (currSum == targetSum)
            {
                res.push_back(currPath);
            }
        }

        helper(root->left, targetSum, currSum, currPath, res);
        helper(root->right, targetSum, currSum, currPath, res);
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        int currSum = 0;
        vector<int> currPath;
        helper(root, targetSum, currSum, currPath, res);
        return res;
    }
};
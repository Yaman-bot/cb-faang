#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        int maxRow = INT_MIN;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                if (!q.empty())
                    q.push(NULL);
                res.push_back(maxRow);
                maxRow = INT_MIN;
            }
            else
            {
                if (temp->val > maxRow)
                    maxRow = temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};
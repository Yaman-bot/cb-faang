#include <iostream>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        q.push({NULL, 0});
        vector<int> v;
        while (!q.empty())
        {
            pair<TreeNode *, int> temp = q.front();
            q.pop();

            if (temp.first == NULL)
            {
                if (temp.second % 2 == 1)
                {
                    reverse(v.begin(), v.end());
                }

                res.push_back(v);

                if (!q.empty())
                    q.push({NULL, temp.second + 1});
                v.clear();
            }
            else
            {
                v.push_back(temp.first->val);
                if (temp.first->left)
                {
                    q.push({temp.first->left, temp.second + 1});
                }
                if (temp.first->right)
                {
                    q.push({temp.first->right, temp.second + 1});
                }
            }
        }
        return res;
    }
};
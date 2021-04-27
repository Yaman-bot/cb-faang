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
    void inorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
        return;
    }
    vector<int> merge(vector<int> v1, vector<int> v2)
    {
        int n1 = v1.size();
        int n2 = v2.size();
        int i = 0;
        int j = 0;
        if (n1 == 0)
            return v2;
        if (n2 == 0)
            return v1;
        vector<int> res;
        while (i < n1 && j < n2)
        {
            if (v1[i] > v2[j])
            {
                res.push_back(v2[j]);
                j++;
            }
            else
            {
                res.push_back(v1[i]);
                i++;
            }
        }
        while (i < n1)
        {
            res.push_back(v1[i]);
            i++;
        }
        while (j < n2)
        {
            res.push_back(v2[j]);
            j++;
        }
        return res;
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> v1;
        inorder(root1, v1);
        vector<int> v2;
        inorder(root2, v2);
        vector<int> result = merge(v1, v2);
        return result;
    }
};
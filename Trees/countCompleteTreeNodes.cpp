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
    //Log N time complexity(all functions)
    int depth(TreeNode *root)
    {
        int count = 0;
        while (root->left != NULL)
        {
            count++;
            root = root->left;
        }
        return count;
    }

    bool check(TreeNode *root, int idx, int d)
    {
        int left = 1;
        int right = int(pow(2, d));
        int pivot = 0;
        for (int i = 0; i < d; i++)
        {
            pivot = (left + right) / 2;
            if (idx <= pivot)
            {
                root = root->left;
                right = pivot;
            }
            else
            {
                root = root->right;
                left = pivot + 1;
            }
        }
        if (root == NULL)
            return false;
        return true;
    }

    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int d = depth(root);
        if (d == 0)
            return 1;

        int left = 1;
        int n_d = 0;
        int right = int(pow(2, d));
        while (left <= right)
        {
            int pivot = (left + right) / 2;
            if (check(root, pivot, d))
            {
                left = pivot + 1;
                n_d = pivot;
            }
            else
            {
                right = pivot - 1;
            }
        }
        int nodesLastLevel = int(pow(2, d) - 1);
        return nodesLastLevel + n_d;
    }
};
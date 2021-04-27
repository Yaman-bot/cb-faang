#include <iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        data = d;
        left = right = NULL;
    }
};

TreeNode *createTree()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    TreeNode *root = new TreeNode(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

bool isSymmetricUtil(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL || root2 == NULL)
        return root1 == root2;

    if (root1 != NULL && root2 != NULL)
    {
        return (root1->data == root2->data) &&
               isSymmetricUtil(root1->left, root2->right) &&
               isSymmetricUtil(root1->right, root2->left);
    }

    else
    {
        return false;
    }
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    if (root->left != NULL && root->right != NULL)
        return isSymmetricUtil(root->left, root->right);
}

int main()
{
    TreeNode *root = createTree();
    if (isSymmetric(root))
    {
        cout << "Tree isSymmetric" << endl;
    }
    else
    {
        cout << "Tree is not Symmetric";
    }
}
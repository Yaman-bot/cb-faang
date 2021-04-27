#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

node *lca(node *root, int a, int b)
{
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    node *left = lca(root->left, a, b);
    node *right = lca(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    else
        return right;
}

int main()
{
    node *root = buildTree();
    node *res = lca(root, 5, 7);
    cout << res << endl;
}
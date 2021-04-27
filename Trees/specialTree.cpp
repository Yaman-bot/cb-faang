#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

void inorder(Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
    return;
}

Node *specialTree(int *a, int s, int e)
{
    if (s > e)
        return NULL;
    int k = s;
    for (int i = s; i <= e; i++)
    {
        if (a[i] > a[k])
        {
            k = i;
        }
    }
    Node *root = new Node(a[k]);
    root->left = specialTree(a, s, k - 1);
    root->right = specialTree(a, k + 1, e);
    return root;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Node *root = specialTree(a, 0, n - 1);
    inorder(root);
    return 0;
}
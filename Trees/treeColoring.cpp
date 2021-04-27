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

Node *createTree()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    Node *root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

Node *findNode(Node *root, int x)
{
    if (root == NULL)
        return NULL;

    if (root->data == x)
        return root;

    Node *left = findNode(root->left, x);
    Node *right = findNode(root->right, x);
    return (left == NULL ? right : left);
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);
    return 1 + leftCount + rightCount;
}

int coloring(Node *root, int x, int n)
{
    Node *t = findNode(root, x);
    int left = countNodes(t->left);
    int right = countNodes(t->right);
    int remaining = n - (left + right) - 1;
    if (left > right + remaining)
        return 1;
    if (right > left + remaining)
        return 1;
    if (remaining > left + right)
        return 1;
    return 0;
}

int main()
{
    int N, n, x;
    cin >> N >> n >> x;
    Node *root = createTree();
    cout << coloring(root, x, n);
}
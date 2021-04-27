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
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

//Preorder
void print(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

Node *createTreeFromTrav(int *in, int *post, int s, int e)
{
    static int i = e;
    //Base Case
    if (s > e)
    {
        return NULL;
    }
    //Rec Case
    Node *root = new Node(post[i]);

    int index = -1;
    for (int j = s; s <= e; j++)
    {
        if (in[j] == post[i])
        {
            index = j;
            break;
        }
    }

    i--;
    root->right = createTreeFromTrav(in, post, index + 1, e);
    root->left = createTreeFromTrav(in, post, s, index - 1);
    return root;
}

int main()
{
    Node *root = buildTree();
}
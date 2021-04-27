#include <bits/stdc++.h>
using namespace std;
char a[1000];
vector<int> v;

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

void StringToInt()
{
    char *ans = strtok(a, " ");
    while (ans != NULL)
    {
        v.push_back(stoi(ans));
        ans = strtok(NULL, " ");
    }
}

Node *CreateTree()
{
    if (strlen(a) == 0 || v.size() == 0)
        return NULL;
    queue<Node *> q;
    int no = v[0];
    Node *root = new Node(no);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < v.size())
    {
        Node *temp = q.front();
        q.pop();
        no = v[i++];
        temp->left = new Node(no);
        q.push(temp->left);
        if (i >= v.size())
        {
            break;
        }
        no = v[i++];
        temp->right = new Node(no);
        q.push(temp->right);
        if (i >= v.size())
        {
            break;
        }
    }
    return root;
}

int Sum(Node *root)
{
    if (root == NULL)
        return 0;
    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);
    return root->data + leftSum + rightSum;
}

int countSubtrees(Node *root, int x)
{
    if (root == NULL)
        return 0;
    int ans = 0;

    if (Sum(root) == x)
    {
        ans = 1;
    }

    int left = countSubtrees(root->left, x);
    int right = countSubtrees(root->right, x);
    return ans + left + right;
}

int main()
{
    int t, x;
    cin >> t;
    while (t--)
    {
        cin.ignore();
        cin.getline(a, 1000);
        StringToInt();
        cin >> x;
        Node *root = CreateTree();
        cout << countSubtrees(root, x) << endl;
    }

    return 0;
}
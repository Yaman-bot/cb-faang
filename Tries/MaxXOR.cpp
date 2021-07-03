#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    Node *left;  //for 0
    Node *right; //for 1
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                    temp->left = new Node();
                temp = temp->left;
            }
            else
            {
                //bit is 1
                if (temp->right == NULL)
                    temp->right = new Node();
                temp = temp->right;
            }
        }
    }

    //helper function
    int max_helper(int n)
    {
        int currAns = 0;
        Node *temp = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (n >> j) & 1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    currAns += (1 << j);
                }
                else
                    temp = temp->left;
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    currAns += (1 << j);
                }
                else
                    temp = temp->right;
            }
        }
        return currAns;
    }
};

class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        int ans = 0;
        Trie trie;
        for (int i = 0; i < nums.size(); i++)
        {
            int val = nums[i];
            trie.insert(val);
            int currAns = trie.max_helper(val);
            ans = max(ans, currAns);
        }
        return ans;
    }
};
#include <stdio.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int val){
            this->val = val;
            next=NULL;
        }
};


void remove(Node *node,int k){
    Node *slow=node;
    Node *fast=node;

    while(k--){
        fast=fast->next;
    }

    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }

    slow->next=slow->next->next;
}
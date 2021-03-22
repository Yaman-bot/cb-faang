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

Node* swapPair(Node *head){
    //base case
    if(head==NULL or head->next==NULL){
        return head;
    }

    Node *smallHead=swapPair(head->next->next);
    Node *temp=head->next;
    temp->next=head;
    head->next=smallHead;
    return temp;
}
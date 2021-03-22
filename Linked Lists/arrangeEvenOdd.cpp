#include <stdio.h>
using namespace std;

class ListNode{
    public:
        int val;
        ListNode *next;

        ListNode(int val){
            this->val = val;
            next=NULL;
        }
};

ListNode *evenOdd(ListNode *node){
    if(node==NULL){
        return NULL;
    }

    ListNode *oddHead=NULL;
    ListNode *oddTail=NULL;
    ListNode *evenHead=NULL;
    ListNode *evenTail=NULL;
    ListNode *temp=node;
    bool isOdd=1;

    while(temp!=NULL){
        if(isOdd){
            if(oddHead==NULL){
                oddHead=oddTail=temp;
            }
            else{
                oddTail->next=temp;
                oddTail=oddTail->next;
            }
            temp=temp->next;
            oddTail->next=NULL;
        }
        else{
            if(evenHead==NULL){
                evenHead=evenTail=temp;
            }
            else{
                evenTail->next=temp;
                evenTail=evenTail->next;
            }
            temp=temp->next;
            evenTail->next=NULL;
        }
        isOdd=!isOdd;
    }
    oddTail->next=evenHead;
    return oddHead;
}

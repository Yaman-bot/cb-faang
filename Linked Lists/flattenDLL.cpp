#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node *child;
    Node(int d)
    {
        data = d;
        next = NULL;
        prev=NULL;
        child=NULL;
    }
};


class Solution{
    public :
        Node* flatten(Node*head){
            if(head==NULL) return head;
            Node *dummy=new Node(0);
            dummy->next=head;
            Node*curr=dummy;
            Node *prev=dummy;
            stack<Node*> s;
            s.push(head);
            while(!s.empty()){
                curr=s.top();
                s.pop();
                prev->next=curr;
                curr->prev=prev;
                if(curr->next!=NULL){
                    s.push(curr->next);
                }
                if(curr->child!=NULL){
                    s.push(curr->child);
                    curr->child=NULL;
                }
                prev=curr;
            }
            dummy->next->prev=NULL;
            return dummy->next;
        }

};

  
// Driver program 
int main() 
{ 
    Node *head = NULL;
    return 0; 
} 
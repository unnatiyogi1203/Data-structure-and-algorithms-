//2. Implementation of Linked list using pointer:

#include <iostream>
using namespace std;
class node{
public:
    int data;
    node* next;
    node(int val){
    data=val;
    next=NULL;
   }
};
void insertAtTail(node* &head,int val){
node* n=new node(val);
if(head==NULL){
    return;
}
node* temp=head;
while(temp->next!=NULL)
{
  temp=temp->next;
}
temp->next=n;
}
void print(node* head){
node* temp = head;
while(temp!=NULL){
    cout<<temp->data<<" " ;
    temp=temp->next;
}
}
int main(){
    node*head = new node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    print(head);
    return 0;
}

//3. Implementation of doubly-linkedlist using pointer:

#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
void print(node *head)
{

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void insertatlast(node *head, int value)
{
    node *p = new node(value);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    temp = p;
}
void insertathead(node *&head, int val)
{
    node *p = new node(val);
    p->next = head;
    head->prev = p;
    head = p;
}
void insertatindex(node *&head, int val, int index)
{
    node *p = head;
    node *node1 = new node(val);
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    node1->next = p->next;
    p->next->prev = node1;
    p->next = node1;
    node1->prev = p;
}
int main()
{
    node *head = new node(12);
    node *temp1 = new node(14);
    node *temp2 = new node(16);
    node *temp3 = new node(18);
    node *temp4 = new node(20);
    head->next = temp1;
    temp1->next = temp2;
    temp2->next = temp3;
    temp3->next = temp4;
    temp4->next = NULL;
    print(head);
    cout << endl;

    insertathead(head, 24);
    cout << "linkedlist after insertion " << endl;

    insertatlast(head, 50);
    cout << "linkedlist after insertion " << endl;
    print(head);

    insertatindex(head, 15, 2);
    cout << "linkedlist after insertion " << endl;
     print(head);
    return 0;
}

//5. Implementation of circular-linkedlist using pointer:

#include <iostream>

using namespace std;
class node
{

public:
    int data;
    node *next;

    node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
// creation of circular linkedlist

void insertatnode(node *&tail, int index, int el)
{

    if (tail == NULL)
    {
        node *newNode = new node(el);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {

        node *temp = tail;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        node *curr = new node(el);
        curr->next = temp->next;
        temp->next = curr;
    }
}

//traversing linkedlist
void print(node *tail)
{
    node *temp = tail;
    do
    {

        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
int main()
{

    node *tail = NULL;
    insertatnode(tail, 5, 3);
    print(tail);

    insertatnode(tail, 3, 4);
    print(tail);

    insertatnode(tail, 4, 9);
    print(tail);

    insertatnode(tail, 9, 7);
    print(tail);

    insertatnode(tail, 4, 5);
    print(tail);

    return 0;
}

//1. Implementation of Linked list using array:

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// Function to insert node at the end
Node* insertEnd(Node* root, int item)
{
    Node* temp = new Node(item);
    if (root == NULL)
        return temp;
  
    Node* last = root;
    while (last->next != NULL) {
        last = last->next;
    }
  
    last->next = temp;
    return root;
}

Node* arrayToList(int arr[], int n)
{
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertEnd(root, arr[i]);
    }
    return root;
}

void display(Node* root)
{
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next;
    }
}

// Driver code
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* root = arrayToList(arr, n);
    display(root);
    return 0;
}


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



//4. Implementation of doubly-linkedlist using array:

#include<bits/stdc++.h>
using namespace std;

// Doubly linked list node
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// Utility function to create a node in memory
struct node* getNode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}

// Function to display the list
int displayList(struct node *temp)
{

    struct node *t = temp;
    if(temp == NULL)
        return 0;
    else
    { 
        cout<<"The list is: ";
        
        while(temp->next != t)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        
        cout<<temp->data;
        
        return 1;
    } 
}


// Function to convert array into list
void createList(int arr[], int n, struct node **start)
{
    // Declare newNode and temporary pointer
    struct node *newNode,*temp;
    int i;
    
    // Iterate the loop until array length
    for(i=0;i<n;i++)
    {
        // Create new node
        newNode = getNode();
        
        // Assign the array data
        newNode->data = arr[i];
        
        // If it is first element
        // Put that node prev and next as start
        // as it is circular
        if(i==0)
        {
            *start = newNode;
            newNode->prev = *start;
            newNode->next = *start;
        }
        else
        { 
            // Find the last node
            temp = (*start)->prev;
            
            // Add the last node to make them
            // in circular fashion
            temp->next = newNode;
            newNode->next = *start;
            newNode->prev = temp;
            temp = *start;
            temp->prev = newNode;
        }
    }
}

// Driver Code
int main()
{
    // Array to be converted
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Start Pointer
    struct node *start = NULL;
    
    // Create the List
    createList(arr, n, &start);
    
    // Display the list
    displayList(start);
    
    return 0;
}



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

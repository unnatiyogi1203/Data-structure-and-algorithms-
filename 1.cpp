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

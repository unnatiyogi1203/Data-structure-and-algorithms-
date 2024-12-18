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

//1. Implementation of stack using array:

#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    int *arr, top, n;
    bool isEmpty();
    int size();

    //where n is the size of the array
    Stack(int x)
    {
        n = x;
        arr = new int[x];
        top = -1;
    }
    Stack(){}
    // function to push the element in an stack
    void push(int element)
    {
        if (n- top > 1)
        {
            top++;
            arr[top] = element;
        }

        else
        {
            cout << "overflow condition " << endl;
        }

    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"underflow condition "<<endl;
        }
    }
    //display the top element of the stack
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"stack is empty "<<endl;
        }
    }
    
};
int main()
{
    class Stack st(5);
    st.push(1);
    cout << "The element at top is : "<< st.peek() << endl;
    st.push(2);
    cout << "The element at top is : "<< st.peek() << endl;
    st.push(3);
    cout << "The element at top is : "<< st.peek() << endl;
    st.push(4);
    cout << "The element at top is : "<< st.peek() << endl;
    st.push(5);
    cout << "The element at top is : "<< st.peek() << endl;
    st.pop();
    st.pop();
    cout<<"after popping of an element the element at top is : "<< st.peek() << endl;

    return 0;
}


//2. Implementation of stack using pointer:
#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        this->next = nullptr;
    }
};

// Class to implement stack using a singly linked list
class Stack {

    // head of the linked list
    Node* head;

public:
    // Constructor to initialize the stack
    Stack() { this->head = nullptr; }

    // Function to check if the stack is empty
    bool isEmpty() {
      
        // If head is nullptr, the stack is empty
        return head == nullptr;
    }

    // Function to push an element onto the stack
   void push(int new_data) {
    
        // Create a new node with given data
        Node* new_node = new Node(new_data);

        // Check if memory allocation for the new node
        // failed
        if (!new_node) {
            cout << "\nStack Overflow";
        }

        // Link the new node to the current top node

        new_node->next = head;
      // Update the top to the new node
head = new_node;
    }

    // Function to remove the top element from the stack
      void pop() {

        // Check for stack underflow
        if (this->isEmpty()) {
            cout << "\nStack Underflow" << endl;
        }
        else {
            // Assign the current top to a temporary
            // variable
            Node* temp = head;

            // Update the top to the next node
            head = head->next;

            // Deallocate the memory of the old top node
            delete temp;
        }
    }

    // Function to return the top element of the stack
      int peek() {

       // If stack is not empty, return the top element
        if (!isEmpty())
            return head->data;
        else {
            cout << "\nStack is empty";
            return INT_MIN;
        }
      }
       };

// Driver program to test the stack implementation
int main() {
    // Creating a stack
    Stack st;

    // Push elements onto the stac
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    // removing two elemements from the top
      cout << "Removing two elements..." << endl;
    st.pop();
    st.pop();

    // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    return 0;
}


//3. Program of Tower of Hanoi using recursion:
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int N = 3;

    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}


//4. Program to find out factorial using recursion. Also find the various state of stack during programs.
#include <iostream>
using namespace std;

// Define a function to calculate factorial
// recursively
long long factorial(int n)
{
    // Base case - If n is 0 or 1, return 1
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case - Return n multiplied by
    // factorial of (n-1)

    return n * factorial(n - 1);
}

int main()
{
    int num = 5;
    // printing the factorial
    cout << "Factorial of " << num << " is "
         << factorial(num) << endl;

    return 0;
}



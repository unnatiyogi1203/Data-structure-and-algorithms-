//1. Implementation of  queue using array:
#include <iostream>
#define SIZE 5 // Define the maximum size of the queue
using namespace std;
class Queue {
private:
    int arr[SIZE]; // Array to store the queue
    int front;     // Index of the front element
    int rear;      // Index of the rear element

public:
    Queue() {
        front = -1;
        rear = -1;
    }
    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }
    // Function to check if the queue is full
    bool isFull() {
        return (rear == SIZE - 1);
    }
    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Initialize front if queue was empty
        }
        arr[++rear] = value;
        cout << "Enqueued " << value << endl;
    }
    // Function to remove an element from the queue
    void dequeue() {
          if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        cout << "Dequeued " << arr[front] << endl;
        if (front == rear) {
            // Reset the queue when the last element is dequeued
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Attempt to enqueue beyond capacity
    q.display();
    return 0;
}


//2. Implementation of queue using pointers:
 
#include <iostream>
using namespace std;

// Node structure for the queue
struct Node {
    int data;       // Value of the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Queue class
class Queue {
private:
    Node* front; // Pointer to the front node
    Node* rear;  // Pointer to the rear node

public:
    // Constructor to initialize the queue
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        Node* newNode = new Node(value); // Create a new node
        if (isEmpty()) {
            // If the queue is empty, both front and rear point to the new node
            front = rear = newNode;
        } else {
            // Add the new node at the rear and update the rear pointer
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }
        Node* temp = front;       // Temporary pointer to the front node
        front = front->next;      // Move the front pointer to the next node
        cout << "Dequeued: " << temp->data << endl;
        delete temp;              // Delete the old front node

        if (front == nullptr) {
            // If the queue is empty after dequeue, reset rear to nullptr
            rear = nullptr;
        }
    }

    // Function to get the front element of the queue
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Function to display the elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;

    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(25);
    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();

    q.enqueue(35);
    q.enqueue(45);
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Attempt to dequeue when queue is empty

    return 0;
}


//3. Implementation of circular queue using array:
#include <iostream>
using namespace std;

class CircularQueue {
private:
    int *queue;      // Pointer to dynamically allocated array
    int front;       // Index of the front element
    int rear;        // Index of the rear element
    int size;        // Maximum size of the queue
    int count;       // Current number of elements in the queue

public:
    // Constructor to initialize the circular queue
    CircularQueue(int maxSize) {
        size = maxSize;
        queue = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor to clean up the allocated memory
    ~CircularQueue() {
        delete[] queue;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
        return count == size;
    }

    // Function to add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full! Cannot enqueue " << value << "." << endl;
            return;
        }

        // Increment rear in a circular manner
        rear = (rear + 1) % size;
        queue[rear] = value;
        count++; // Increase the element count
        cout << "Enqueued: " << value << endl;
    }

    // Function to remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << queue[front] << endl;

        // Move front forward in a circular manner
        front = (front + 1) % size;
        count--; // Decrease the element count
    }

    // Function to get the front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element." << endl;
            return -1;
        }
        return queue[front];
    }

    // Function to get the rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty! No rear element." << endl;
            return -1;
        }
        return queue[rear];
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % size; // Calculate the current index
            cout << queue[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq(5); // Create a circular queue with size 5

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    cout << "Front element: " << cq.getFront() << endl;
    cout << "Rear element: " << cq.getRear() << endl;

    cq.dequeue();
    cq.display();

    return 0;
}

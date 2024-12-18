//1. Implementation of sorting
     //a.  Bubble sort

      #include <iostream>
    using namespace std;

   void bubbleSort(int arr[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n-1; i++) {
        // Flag to check if any swapping happens in the inner loop
        bool swapped = false;

        // Last i elements are already sorted, so we reduce the range
        for (int j = 0; j < n-i-1; j++) {
            // If the element is greater than the next element, swap them
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }

        // If no two elements were swapped by inner loop, then the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    // Perform Bubble Sort
    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

 
//b. selection sort

 #include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    // Traverse through all array elements
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part of the array
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    // Perform Selection Sort
    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

//c. insertion
#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    insertionSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

 
//d. quick

#include <iostream>
using namespace std;

// Function to partition the array into two halves based on the pivot
int partition(int arr[], int low, int high) {
    // Choose the rightmost element as the pivot
    int pivot = arr[high];
    
    // Pointer for the smaller element
    int i = (low - 1);
    
    // Traverse the array and rearrange elements based on the pivot
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to the pivot, swap it
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // Place the pivot element at its correct position in the array
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array into two halves and get the pivot index
        int pi = partition(arr, low, high);
        
        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);  // Sort elements before the pivot
        quickSort(arr, pi + 1, high); // Sort elements after the pivot
    }
}
// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    // Perform Quick Sort
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}


//e. merge sort
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}




//2. Implementation of Binary Search on a list of numbers stored in an Array
#include <iostream>
using namespace std;

// Function to perform Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    // Loop until the search space is empty
    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle element

        // Check if target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found, return the index
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target not found
    return -1;
}

int main() {
    // Example array (must be sorted for Binary Search)
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int target;
    cout << "Enter the number to search for: ";
    cin >> target;

    // Perform Binary Search
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}



//3. Implementation of Binary Search on a list of strings stored in an Array
#include <iostream>
#include <string>
using namespace std;

// Function to perform Binary Search on a list of strings
int binarySearch(string arr[], int size, string target) {
    int left = 0;
    int right = size - 1;

    // Loop until the search space is empty
    while (left <= right) {
        int mid = left + (right - left) / 2; // Find the middle index

        // Check if the target is present at mid
        if (arr[mid] == target) {
            return mid; // Target found, return the index
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Target not found
    return -1;
}

int main() {
    // Example sorted array of strings
    string arr[] = {"apple", "banana", "cherry", "date", "grape", "kiwi", "mango", "orange", "pear", "watermelon"};
    int size = sizeof(arr) / sizeof(arr[0]);

    string target;
    cout << "Enter the string to search for: ";
    cin >> target;

    // Perform Binary Search
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}


//4. Implementation of Linear Search on a list of strings stored in an Array
#include <iostream>
#include <string>
using namespace std;

// Node structure for singly linked list
struct Node {
    string data;
    Node* next;

    Node(string value) {
        data = value;
        next = nullptr;
    }
};

// Function to add a node to the linked list
void append(Node*& head, const string& value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to find the middle node using slow and fast pointers
Node* findMiddle(Node* left, Node* right) {
    if (!left) return nullptr;
    
    Node* slow = left;
    Node* fast = left;
    
    while (fast != right && fast->next != right) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to perform binary search on the linked list
Node* binarySearch(Node* head, const string& target) {
    if (!head) return nullptr;

    Node* left = head;
    Node* right = nullptr;

    while (left != right) {
        Node* mid = findMiddle(left, right);

        // Compare mid's data with the target
        if (mid->data == target) {
            return mid; // Target found
        }

        // If target is greater, search in the right half
        if (mid->data < target) {
            left = mid->next;
        }
        // If target is smaller, search in the left half
        else {
            right = mid;
        }
    }

    return nullptr; // Target not found
}

int main() {
    Node* head = nullptr;
    
    // Adding elements to the linked list
    append(head, "apple");
    append(head, "banana");
    append(head, "cherry");
    append(head, "date");
    append(head, "grape");
    append(head, "kiwi");
    append(head, "mango");
    append(head, "orange");
    append(head, "pear");
    append(head, "watermelon");

    string target;
    cout << "Enter the string to search for: ";
    cin >> target;

    // Perform binary search on the linked list
    Node* result = binarySearch(head, target);

    if (result != nullptr) {
        cout << "Element found: " << result->data << endl;
    } else {
        cout << "Element not found!" << endl;
    }

    return 0;
}

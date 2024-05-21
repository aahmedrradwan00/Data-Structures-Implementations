#include <bits/stdc++.h>

using namespace std;

// Template class for a circular queue implemented using a dynamic array
template<class t>
class queuearray {
    int front; // Index of the front element
    int rear;  // Index of the rear element
    int length; // Current number of elements in the queue
    t *arr; // Pointer to the array that holds the queue elements
    int maxSize; // Maximum capacity of the queue

public:
    // Constructor to initialize the queue with a specified size
    queuearray(int size) {
      if (size <= 0)
        maxSize = 100; // Default size if an invalid size is provided
      else
        maxSize = size;

      front = 0; // Initialize front index
      arr = new t[maxSize]; // Allocate memory for the array
      rear = maxSize - 1; // Initialize rear index
      length = 0; // Initialize length
    }

    // Function to check if the queue is empty
    bool isEmpty() {
      return length == 0;
    }

    // Function to check if the queue is full
    bool isFull() {
      return length == maxSize;
    }

    // Function to add an element to the rear of the queue
    void Enqueue(t element) {
      if (isFull())
        cout << "Queue is full\n";
      else {
        rear = (rear + 1) % maxSize; // Circular increment
        arr[rear] = element; // Add element at the rear
        length++;
      }
    }

    // Function to remove an element from the front of the queue
    void Dequeue() {
      if (isEmpty())
        cout << "Queue is empty\n";
      else {
        front = (front + 1) % maxSize; // Circular increment
        length--;
      }
    }

    // Function to get the front element of the queue
    void getFront() {
      if (isEmpty()) {
        cout << "Queue is empty\n";
      } else {
        cout << arr[front] << "\n";
      }
    }

    // Function to get the rear element of the queue
    void getRear() {
      if (isEmpty()) {
        cout << "Queue is empty\n";
      } else {
        cout << arr[rear] << "\n";
      }
    }

    // Function to display the elements of the queue
    void display() {
      if (isEmpty())
        cout << "Queue is empty\n";
      else {
        for (int i = front; i != rear; i = (i + 1) % maxSize) {
          cout << arr[i] << " "; // Print each element
        }
        cout << arr[rear] << " "; // Print the rear element
        cout << endl;
      }
    }

    // Function to search for an element in the queue
    bool search(t item) {
      bool found = false;
      for (int i = front; i != rear; i = (i + 1) % maxSize) {
        if (item == arr[i]) {
          found = true;
          break;
        }
      }
      if (item == arr[rear]) { // Check the rear element separately
        found = true;
      }
      if (found) cout << "The item is found\n";
      else cout << "Item is not found\n";

      return found;
    }
};

int main() {
  queuearray<int> q(5);
  q.Enqueue(10);
  q.Enqueue(20);
  q.Enqueue(30);
  q.Enqueue(40);
  q.Enqueue(50);

  q.display();
  q.getFront();
  q.getRear();

  q.Dequeue();
  q.display();

  q.Dequeue();
  q.display();
}

#include <bits/stdc++.h>

using namespace std;

// Node class to represent each element in the queue
class Node {
public:
    int data; // Data part of the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a node with default values
    Node() {
      data = 0; // Initialize data to 0
      next = NULL; // Initialize next pointer to NULL
    }
};

// Queue class
class Queue {
public:
    Node *front; // Pointer to the front (first) node of the queue
    Node *rear; // Pointer to the rear (last) node of the queue

    // Constructor to initialize the queue
    Queue() {
      front = rear = NULL; // Initially, both front and rear are NULL (empty queue)
    }

    // Function to check if the queue is empty
    bool isEmpty() {
      return front == NULL; // Return true if front is NULL, indicating the queue is empty
    }

    // Function to enqueue (add) an item to the queue
    void Enqueue(int item) {
      Node *newnode = new Node();
      newnode->data = item;
      if (isEmpty()) {
        front = rear = newnode; // If the queue is empty, both front and rear point to the new node
      } else {
        rear->next = newnode; // Otherwise, link the new node to the rear node
        rear = newnode;
      }
    }

    // Function to display all elements in the queue
    void display() {
      if (isEmpty()) {
        cout << "Queue is empty\n";
      } else {
        Node *temp = front;
        while (temp != NULL) {
          cout << temp->data << " ";
          temp = temp->next;
        }
        cout << endl;
      }
    }

    // Function to dequeue (remove) an item from the queue
    int Dequeue() {
      int delvalue = -1;
      if (isEmpty()) {
        cout << "The queue is empty\n";
      } else if (front == rear) {
        delete front;
        front = rear = NULL; // Reset both front and rear to NULL
      } else {
        Node *delptr = front; // Pointer to the node to be deleted (front node)
        front = front->next;
        delvalue = delptr->data;
        delete delptr;
      }
      return delvalue; // Return the deleted value (or -1 if the queue was empty)
    }

    // Function to get the data of the front node
    int getFront() {
      return front->data;
    }

    // Function to get the data of the rear node
    int getrear() {
      return rear->data;
    }

    // Function to count the number of elements in the queue
    void count() {
      Node *temp = front; // Start from the front of the queue
      int counter = 0;
      while (temp != NULL) {
        counter++;
        temp = temp->next; // Move to the next node
      }
      cout << counter << "\n";
    }

    // Function to check if a specific item exists in the queue
    void isfound(int item) {
      bool found = false;
      Node *temp = front;
      while (temp != NULL) {
        if (temp->data == item) {
          found = true; // Set the flag if the item is found
          break;
        }
        temp = temp->next; // Move to the next node
      }
      if (found) cout << item << " is Found\n";
      else cout << item << " is Not Found\n";
    }

    // Function to clear all items from the queue
    void Clear() {
      while (!isEmpty()) {
        Dequeue();
      }
    }
};

int main() {
  Queue q;
  q.Enqueue(1);
  q.Enqueue(4);
  q.Enqueue(8);
  q.Enqueue(42);
  q.Enqueue(15);

  q.display();

  q.isfound(4);
  q.isfound(1000);
  q.count();

//  q.Clear();
//  q.display();

  return 0;
}

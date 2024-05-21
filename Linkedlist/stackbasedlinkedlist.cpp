#include <bits/stdc++.h>

using namespace std;

// Node class for creating individual nodes
class Node {
public:
    int data;
    Node *next;

    // Constructor to initialize node
    Node() {
      data = 0;
      next = NULL;
    }
};

// Stack class to implement stack operations
class Stack {
    Node *top;
public:
    // Constructor to initialize top pointer
    Stack() {
      top = NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
      return top == NULL;
    }

    // Function to push an item onto the stack
    void push(int item) {
      Node *newnode = new Node();
      newnode->data = item;
      if (isEmpty()) {
        newnode->next = NULL;
        top = newnode;
      } else {
        newnode->next = top;
        top = newnode;
      }
    }

    // Function to pop an item from the stack
    int pop() {
      int value;
      Node *delpte = top;
      value = top->data;
      top = top->next;
      delete delpte;
      return value;
    }

    // Function to display the contents of the stack
    void Display() {
      Node *temp = top;
      while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << endl;
    }

    // Function to peek at the top element of the stack
    int peek() {
      return top->data;
    }

    // Function to count the number of elements in the stack
    void count() {
      int counter = 0;
      Node *temp = top;
      while (temp != NULL) {
        counter++;
        temp = temp->next;
      }
      cout << counter << "\n";
    }

    // Function to check if an item is present in the stack
    void isfound(int item) {
      bool found = false;
      Node *temp = top;
      while (temp != NULL) {
        if (temp->data == item) // Corrected comparison operator
          found = true;
        temp = temp->next;
      }
      if (found) cout << item << " is Found\n";
      else cout << item << " is Not Found\n";
    }

    // Function to check if the stack is full
    void isfull() {
      Node *ptr = new Node();
      if (ptr == NULL)
        cout << "stack is full cant add more";
      else cout << "stack is not-full add more\n";
    }
};

int main() {

  Stack s;
  s.push(1);
  s.push(7);
  s.push(12);
  s.push(34);
  s.push(52);

  s.Display();

  s.pop();
  s.Display();
  s.count();

  s.isfull();

  s.isfound(12);
  s.isfound(1000);
}

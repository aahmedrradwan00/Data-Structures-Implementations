#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

// Template class for a stack
template<class t>
class Stack {
    int top; // Index of the top element
    t item[MAX_SIZE]; // Array to store stack elements

public:
    // Constructor to initialize the stack
    Stack() {
      top = -1; // Initialize top index to -1 (empty stack)
    }

    // Function to push an element onto the stack
    void push(t Element) {
      if (top >= MAX_SIZE - 1) {
        cout << "Stack full on push\n"; // Check if stack is full
      } else {
        top++; // Increment top index
        item[top] = Element; // Store element at the top
      }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
      return top < 0;
    }

    // Function to pop (remove) the top element from the stack
    void pop() {
      if (isEmpty())
        cout << "Stack is empty\n";
      else
        top--;
    }

    // Function to get the top element of the stack
    void getTop() {
      if (isEmpty())
        cout << "Stack is empty\n";
      else {
        cout << item[top] << endl;
      }
    }

    // Function to print all elements of the stack
    void print() {
      for (int i = top; i >= 0; i--) {
        cout << item[i] << " ";
      }
      cout << endl;
    }
};

int main() {
  Stack<int> s;
  s.push(5);
  s.push(10);
  s.push(15);
  s.push(20);

  s.print();

  s.getTop();

  s.pop();
  s.push(7);
  s.print();
}

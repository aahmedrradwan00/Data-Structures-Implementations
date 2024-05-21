#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Linkedlist {
public:
    Node *head;

    // Constructor to initialize the linked list
    Linkedlist() {
      head = NULL;
    }

    // Function to check if the linked list is empty
    bool isempty() {
      return (head == NULL);
    }

    // Function to insert a new node at the beginning
    void insertFrist(int newvalue) {
      Node *newnode = new Node();
      newnode->data = newvalue;
      if (isempty()) {
        newnode->next = NULL;
        head = newnode;
      } else {
        newnode->next = head;
        head = newnode;
      }
    }

    // Function to display the elements
    void display() {
      Node *temp = head;
      while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
      }
      cout << "\n";
    }

    // Function to count the number of elements
    int count() {
      int counter = 0;
      Node *temp = head;
      while (temp != NULL) {
        counter++;
        temp = temp->next;
      }
      return counter;
    }

    // Function to check if a given key is present
    bool isfound(int key) {
      bool found = false;
      Node *temp = head;
      while (temp != NULL) {
        if (temp->data == key)
          found = true;
        temp = temp->next;
      }
      return found;
    }

    // Function to insert a new node before a specific item
    void insertbefore(int item, int newvalue) {
      if (isempty()) {
        insertFrist(newvalue);
      }
      if (isfound(item)) {
        Node *newnode = new Node();
        newnode->data = newvalue;
        Node *temp = head;
        while (temp != NULL && temp->data != item) {
          temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
      } else {
        cout << "Sorry, item not found\n";
      }
    }

    // Function to append a new node at the end
    void append(int newvalue) {
      if (isempty()) {
        insertFrist(newvalue);
      }
      Node *newnode = new Node();
      newnode->data = newvalue;
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newnode;
      newnode->next = NULL;
    }

    // Function to delete a node containing a specific item from the linked list
    void Delete(int item) {
      if (isempty()) {
        cout << "List is empty, no items to delete\n";
      }
      if (head->data == item) {
        Node *delptr = head;
        head = head->next;
        delete delptr;
      } else {
        Node *prev = NULL;
        Node *delptr = head;
        while (delptr->data != item) {
          prev = delptr;
          delptr = delptr->next;
        }
        prev->next = delptr->next;
        delete delptr;
      }
    }
};

int main() {
  Linkedlist lst;


  lst.insertFrist(1);
  lst.insertFrist(10);
  lst.insertFrist(12);
  lst.insertFrist(17);
  lst.insertFrist(24);

  lst.display();
  lst.count();

  lst.insertbefore(10, 7);
  lst.append(15);
  lst.display();

  lst.Delete(17);
  lst.display();

  if (lst.isempty()) cout << "the list is empty\n";

  return 0;
}

#include <bits/stdc++.h>

using namespace std;

// Class definition for a Node in the Binary Search Tree (BST)
class Node {
public:
    int data; // Data stored in the node
    Node *left, *right; // Pointers to the left and right child nodes

    // Constructor to initialize a node with a given value
    Node(int value) {
      data = value;
      left = right = NULL;
    }
};

// Class definition for the Binary Search Tree (BST)
class BST {
public:
    Node *root; // Pointer to the root of the BST

    // Constructor to initialize the BST with an empty root
    BST() {
      root = NULL;
    }

    // Recursive function to insert a new value into the BST
    Node *Insert(Node *r, int item) {
      if (r == NULL) {
        Node *newnode = new Node(item); // Create a new node with the given item
        r = newnode; // Set the new node as the root if the tree is empty
      } else if (item < r->data)
        r->left = Insert(r->left, item); // Recursively insert in the left subtree
      else
        r->right = Insert(r->right, item); // Recursively insert in the right subtree

      return r;
    }

    // Public function to insert a new value into the BST
    void Insert(int item) {
      root = Insert(root, item);
    }

    // Function to perform preorder traversal (root, left, right)
    void Preorder(Node *r) {
      if (r == NULL)
        return;
      cout << r->data << " ";
      Preorder(r->left);
      Preorder(r->right);
    }

    // Function to perform inorder traversal (left, root, right)
    void Inorder(Node *r) {
      if (r == NULL)
        return;
      Inorder(r->left);
      cout << r->data << "\t";
      Preorder(r->right);
    }

    // Function to perform postorder traversal (left, right, root)
    void Postorder(Node *r) {
      if (r == NULL)
        return;
      Postorder(r->left);
      Preorder(r->right);
      cout << r->data << "\t";
    }

    // Recursive function to search for a key in the BST
    Node *Search(Node *r, int key) {
      if (r == NULL)
        return NULL;
      else if (r->data == key)
        return r;
      else if (r->data > key)
        return Search(r->left, key);
      else
        return Search(r->right, key);
    }

    // Public function to search for a key in the BST
    bool Search(int key) {
      Node *result = Search(root, key);
      return result != NULL;
    }

    // Function to find the minimum value in the BST
    Node *Findmin(Node *r) {
      if (r == NULL)
        return NULL;
      else if (r->left == NULL)
        return r;
      else
        return Findmin(r->left);
    }

    // Function to find the maximum value in the BST
    Node *Findmax(Node *r) {
      if (r == NULL)
        return NULL;
      else if (r->right == NULL)
        return r;
      else
        return Findmax(r->right);
    }

    // Recursive function to delete a node from the BST
    Node *Delete(Node *r, int key) {
      if (r == NULL)
        return NULL;
      if (key < r->data)
        r->left = Delete(r->left, key);
      else if (key > r->data)
        r->right = Delete(r->right, key);
      else {
        if (r->left == NULL && r->right == NULL)
          r = NULL;
        else if (r->left != NULL && r->right == NULL) {
          r->data = r->left->data;
          delete r->left;
          r->left = NULL;
        } else if (r->left == NULL && r->right != NULL) {
          r->data = r->right->data;
          delete r->right;
          r->right = NULL;
        } else {
          Node *max = Findmax(r->left);
          r->data = max->data;
          Delete(r->left, max->data);
        }
      }
      return r;
    }

    // Function to calculate the size (number of nodes) of the BST
    int Size(Node *r) {
      if (r == NULL)
        return 0;
      else
        return (1 + Size(r->left) + Size(r->right));
    }
};

int main() {
  BST btree;
  btree.Insert(45);
  btree.Insert(15);
  btree.Insert(79);
  btree.Insert(90);
  btree.Insert(10);
  btree.Insert(55);
  btree.Insert(12);
  btree.Insert(20);
  btree.Insert(50);

  cout << "Display the Tree Content\n";
  btree.Preorder(btree.root);
  cout << "\n";


//  btree.Inorder(btree.root);
//  cout << "\n....................................\n";
//  btree.Postorder(btree.root);
//  cout << "\n....................................\n";

  int key;
  cout << "Enter Number To Search\n";
  cin >> key;
  if (btree.Search(key))
    cout << "Item Found\n";
  else
    cout << "Sorry, Item NOT Found\n";

  cout << "Find Minimum \n";
  Node *min = btree.Findmin(btree.root);
  if (min == 0)
    cout << "No Item Exist";
  else
    cout << "Minimum Number : " << min->data << endl;

  cout << "Find Maximum \n";
  Node *max = btree.Findmax(btree.root);
  if (max == 0)
    cout << "No Item Exist";
  else
    cout << "Maximum Number : " << max->data << endl;

  Node *result = btree.Delete(btree.root, 12);
  btree.Preorder(result);

  int s = btree.Size(btree.root);
  cout << "Number of elements = " << s;
}

#include <bits/stdc++.h>

using namespace std;

class Array {
private:
    int size; // Maximum size of the array
    int lenght; // Current number of elements in the array
    int *items; // Pointer to the array elements

public:
    // Constructor to initialize the array with a given size
    Array(int Arrsize) {
      size = Arrsize;
      lenght = 0;
      items = new int[Arrsize]; // Allocate memory for the array
    }

    // Method to fill the array with user input
    void Fill() {
      int numitem;
      cout << "How many items?\n";
      cin >> numitem;
      if (numitem > size) {
        cout << "Fill operation failed"; // Error if more items than the array size
        return;
      } else {
        for (int i = 0; i < numitem; i++) {
          cout << "Enter num " << i + 1 << "\n";
          cin >> items[i]; // Read each item
          lenght++;
        }
      }
    }

    // Method to display the array contents
    void Display() {
      cout << "Display array\n";
      for (int i = 0; i < lenght; i++) {
        cout << items[i] << "\t";
      }
      cout << "\n";
    }

    int Getsize() {
      return size;
    }

    int Getlenght() {
      return lenght;
    }

    // Method to search for a key in the array and return its index
    int Search(int key) {
      int index = -1; // Initialize with -1 to indicate not found
      for (int i = 0; i < lenght; i++) {
        if (items[i] == key) {
          index = i; // Key found at index i
          break;
        }
      }
      return index;
    }

    // Method to append a new item to the array
    void Append(int newitem) {
      if (lenght < size) {
        items[lenght] = newitem; // Add new item at the end
        lenght++;
      } else
        cout << "Array is full\n"; // Error if array is already full
    }

    // Method to insert a new item at a specific index
    void Insert(int index, int newitem) {
      if (index >= 0 && index < size) {
        for (int i = lenght; i > index; i--) {
          items[i] = items[i - 1]; // Shift elements to the right
        }
        items[index] = newitem; // Insert new item
        lenght++;
      } else
        cout << "Error\n"; // Error if index is out of bounds
    }

    // Method to delete an item at a specific index
    void Delete(int index) {
      if (index >= 0 && index < size) {
        for (int i = index; i < lenght - 1; i++) {
          items[i] = items[i + 1]; // Shift elements to the left
        }
        lenght--;
      }
    }

    // Method to enlarge the array size
    void Enlarge(int newsize) {
      if (newsize <= size) {
        cout << "New size must be larger than current size\n";
        return;
      } else {
        size = newsize;
        int *old = items; // Save old array pointer
        items = new int[newsize]; // Allocate new larger array

        for (int i = 0; i < lenght; i++) {
          items[i] = old[i]; // Copy old elements to new array
        }
        delete[] old; // Free old array memory
      }
    }

    // Method to merge another array into this array
    void Merge(Array other) {
      int newsize = size + other.Getsize(); // Calculate new size
      size = newsize;
      int *old = items; // Save old array pointer
      items = new int[newsize]; // Allocate new larger array
      int i;
      for (int i = 0; i < lenght; i++) {
        items[i] = old[i]; // Copy old elements to new array
      }
      delete[] old; // Free old array memory
      int j = i;
      for (int i = 0; i < other.Getlenght(); i++) {
        items[j++] = other.items[i]; // Append other array's elements
        lenght++;
      }
    }
};

int main() {
  int arraysize;
  cout << "Size of your array\n";
  cin >> arraysize;
  Array myarray(arraysize);
  myarray.Fill();
  cout << "Array size: " << myarray.Getsize() << "\t";
  cout << "Array length: " << myarray.Getlenght() << "\n";

  myarray.Display();

  cout << "Enter value to search\n";
  int key;
  cin >> key;
  int index = myarray.Search(key);
  if (index == -1)
    cout << "Item not found\n";
  else
    cout << "Item found at position = " << index << "\n";

  int newitem;
  cout << "Enter number to append\n";
  cin >> newitem;
  myarray.Append(newitem);
  myarray.Display();

  cout << "Enter index and new item\n";
  cin >> index;
  cin >> newitem;
  myarray.Insert(index, newitem);

  myarray.Display();

  cout << "Index to delete\n";
  cin >> index;
  myarray.Delete(index);
  myarray.Display();

  int newsize;
  cout << "Enter new size\n";
  cin >> newsize;
  myarray.Enlarge(newsize);
  cout << "Array size: " << myarray.Getsize() << "\t";
  cout << "Array length: " << myarray.Getlenght() << "\n";
  myarray.Display();

  Array other(3);
  other.Fill();
  myarray.Merge(other);
  cout << "Array size: " << myarray.Getsize() << "\t";
  cout << "Array length: " << myarray.Getlenght() << "\n";
  myarray.Display(); 
}

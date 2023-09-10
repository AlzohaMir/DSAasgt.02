//1 Retrieving The Trump

//The code reads commands from an input file to manipulate a linked list. 
//Supported commands: "ADD" (add an element), "DELETE" (remove the last element), and "END" (end input). 
//The program prints the linked list's elements and identifies the middle element(s) as the lucky winner(s). 
//It manages file input/output and dynamic memory allocation for nodes




#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Define a structure for a linked list node
struct Node {
    int data;
    Node* next;
};

// Define a class for a singly linked list
class LinkedList {
private:
    Node* head;  // Pointer to the first node in the list
    Node* tail;  // Pointer to the last node in the list

public:
    // Constructor: Initializes head and tail to NULL for an empty list
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Print the elements of the linked list
    void print() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
            return;
        }

        Node* current = head;

        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }

        cout << "null" << endl;
    }

    // Add a new element to the end of the linked list
    void add(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove the last element from the linked list
    void remove() {
        if (head == NULL) {
            return;
        } else if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* current = head;

            while (current->next != tail) {
                current = current->next;
            }

            delete tail;
            tail = current;
            tail->next = NULL;
        }
    }

    // Print the middle element(s) of the linked list
    void printMiddle() {
        if (head == NULL) {
            cout << "The linked list is empty." << endl;
            return;
        }

        Node* slowPtr = head;
        Node* fastPtr = head;
        Node* prevSlowPtr = NULL;

        while (fastPtr != NULL && fastPtr->next != NULL) {
            prevSlowPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        if (fastPtr == NULL) {
            cout << "The lucky winners are: " << prevSlowPtr->data << " and " << slowPtr->data << endl;
        } else {
            cout << "The lucky winner is: " << slowPtr->data << endl;
        }
    }
};

int main() {
    LinkedList list;

    // Open an input file
    ifstream inputFile("C:/Users/sg/Desktop/Q1/t2.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return 0;
    }

    string command, line;

    // Read commands from the input file and perform operations on the linked list
    while (inputFile >> command) {
        if (command == "ADD") {
            int data;
            inputFile >> data;
            list.add(data);
        } else if (command == "DELETE") {
            list.remove();
        } else if (command == "END") {
            break;
        }
    }

    inputFile.close();

    // Print the linked list
    cout << "Linked list: ";
    list.print();

    // Print the middle element(s) of the linked list
    list.printMiddle();

    cout << endl;

    return 0;
}


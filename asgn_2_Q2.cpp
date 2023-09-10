//2 Survival of the Fittest

//The code defines a doubly linked list and a class LinkedList to manage sorted elements.
//It reads input from a text file, where each line contains a series of integers.
//For each line, it inserts integers into the linked list while maintaining their sorted order.
//It calculates and prints the median of the elements in the list after each insertion.
//This code demonstrates the insertion of sorted elements and computes the median efficiently.A



#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Define a structure for a doubly linked list node
struct Node {
    int data;
    Node* prev, * next;
    Node(int data) : data(data), prev(NULL), next(NULL) {}
};

// Define a class for a sorted doubly linked list
class LinkedList {
private:
    Node* head, * tail;
    int size;

public:
    // Constructor: Initializes an empty linked list
    LinkedList() : head(NULL), tail(NULL), size(0) {}

    // Inserts a new element into the sorted linked list while maintaining order
    void insert(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else if (data <= head->data) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (data >= tail->data) {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else {
            Node* curr = head;
            while (curr && curr->data < data) {
                curr = curr->next;
            }
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
        size++;
    }

    // Calculates and returns the median of the elements in the linked list
    double getMedian() {
        if (!head) return 0.0;

        Node* curr = head;
        int mid = floor(size / 2.0);
        for (int i = 0; i < mid; i++) {
            curr = curr->next;
        }
        if (size % 2 == 1) return curr->data;
        else return (curr->data + curr->prev->data) / 2.0;
    }
};

int main() {
    LinkedList list;

    // Open an input file
    ifstream file("C:/Users/sg/Desktop/Q2/t2.txt");
    string line;

    // Read lines from the input file and process each line
    while (getline(file, line)) {
        stringstream ss(line);
        int num;

        // Read numbers from the current line and insert them into the sorted list
        while (ss >> num) {
            list.insert(num);
            cout << list.getMedian() << endl;
        }
    }

    file.close();
    return 0;
}


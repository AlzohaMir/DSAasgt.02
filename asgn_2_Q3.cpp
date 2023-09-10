//3 Reversing the Irreversible

//The program implements a singly linked list data structure to manage financial transaction records.
//The program reads input data from a text file, including the number of total transactions and the number of fraudulent transactions.
//It parses transaction data from the file and inserts it into the linked list.
//Fraudulent transactions are identified and removed from the list based on their transaction IDs.
//The program prints the remaining valid transactions in the linked list.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Define a structure for a Node in the linked list.
struct Node {
    string transactionId;
    int transactionAmount;
    Node *next;
    
    // Constructor to initialize a Node with transaction information.
    Node(string transactionId, int transactionAmount) : transactionId(transactionId), transactionAmount(transactionAmount), next(NULL) {}
};

// Define a class for a singly linked list.
class LinkedList {
private:
    Node *head;  // Pointer to the head of the list.

public:
    LinkedList() : head(NULL) {}

    // Insert a new Node at the beginning of the list.
    void insert(string transactionId, int transactionAmount) {
        Node *newNode = new Node(transactionId, transactionAmount);
        newNode->next = head;
        head = newNode;
    }

    // Remove a Node with a specified transactionId from the list.
    void remove(string transactionId) {
        if (!head) return;  // Return if the list is empty.

        // Check if the Node to be removed is the head of the list.
        if (head->transactionId == transactionId) {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Search for the Node to remove and adjust pointers.
        Node *curr = head;
        while (curr->next && curr->next->transactionId != transactionId) {
            curr = curr->next;
        }
        if (!curr->next) return;  // Return if the Node was not found.

        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }

    // Print the content of the linked list.
    void print() {
        Node *curr = head;
        while (curr) {
            cout << curr->transactionId << "," << curr->transactionAmount << endl;
            curr = curr->next;
        }
    }
};

int main() {
    LinkedList list;  // Create an instance of the LinkedList class.

    ifstream file("C:/Users/sg/Desktop/Q3/t1.txt");  // Open a file for reading.
    string line;

    // Read the first line of the file to get transaction counts.
    getline(file, line);
    stringstream ss(line);
    int numberOfTransactions, numberOfFraudulentTransactions;
    ss >> numberOfTransactions >> numberOfFraudulentTransactions;

    // Parse and insert transaction data into the linked list.
    for (int i = 0; i < numberOfTransactions; i++) {
        getline(file, line);
        size_t pos = line.find(",");
        string transactionId = line.substr(0, pos);
        string str = line.substr(pos + 1);
        stringstream ss(str);
        int transactionAmount;
        ss >> transactionAmount;
        list.insert(transactionId, transactionAmount);
    }

    // Remove fraudulent transactions from the linked list.
    for (int i = 0; i < numberOfFraudulentTransactions; i++) {
        getline(file, line);
        list.remove(line);
    }

    // Print the remaining transactions in the linked list.
    list.print();

    file.close();  // Close the file.
    return 0;
}



//5 As the Matter of Third

//The program reads integer values from a text file (t4.txt) and stores them in a double-ended queue (deque).
//It counts and displays the total number of elements in the deque, indicating the size of the dataset.
//The program checks if the deque contains at least three elements.
//If there are three or more elements, it prints the third-to-last element in the deque.
//If the deque has less than three elements, it provides a message indicating that the dataset is too small for this operation.


#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <sstream>

using namespace std;

int main() {
    // Open a file for reading.
    ifstream file("C:/Users/sg/Desktop/Q5/t4.txt");
    string line;
    
    // Create a deque (double-ended queue) to store integers from the file.
    deque<int> linkedList;

    // Read each line of the file.
    while (getline(file, line)) {
        stringstream ss(line);
        int num;
        
        // Parse integers from the line and add them to the deque.
        while (ss >> num) {
            linkedList.push_back(num);
        }
    }

    // Print the number of elements in the deque.
    cout << "Number of elements: " << linkedList.size() << endl;

    // Check if there are at least three elements in the deque.
    if (linkedList.size() >= 3) {
        // Print the third last element in the deque.
        cout << "Third last element: " << linkedList[linkedList.size() - 3] << endl;
    } else {
        // Print a message if the deque has less than three elements.
        cout << "The linked list has less than 3 elements." << endl;
    }

    // Close the file.
    file.close();
    return 0;
}



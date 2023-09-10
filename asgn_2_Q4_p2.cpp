//4 The Editor

//The program defines a class called Editor that manages a list of integers (data) and maintains a cursor within the list, along with a history of changes.
//Editor provides various methods for manipulating the list, including adding, deleting, updating, shifting, and undoing actions.
//Input commands are read from a text file (t1.txt) and executed on an Editor object, supporting operations like add, delete, move, update, and more.
//The program reports cursor movement during "MoveForward" and "MoveBackward" operations and prints the list contents with the "Print" command.




#include <iostream>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;

// Define a text editor class
class Editor {
    list<int> data;                // List of integers
    list<int>::iterator cursor;    // Iterator for the current cursor position
    list<list<int>> history;       // History of changes to the list

public:
    // Constructor initializes the cursor to the beginning of the list
    Editor() {
        cursor = data.begin();
    }

    // Add a number to the end of the list
    void addNumber(int number) {
        data.push_back(number);
        if (data.size() == 1) {
            cursor = data.begin();
        }
        history.push_back(data);
    }

    // Delete the last element from the list
    void deleteTail() {
        if (!data.empty()) {
            list<int>::iterator it = data.end();
            it--;
            if (it == cursor) {
                cursor = data.begin();
            }
            data.erase(it);
            history.push_back(data);
        }
    }

    // Insert a number at a specified index in the list
    void addAtIndex(int index, int number) {
        if (index <= data.size()) {
            list<int>::iterator it = data.begin();
            advance(it, index + 1);
            data.insert(it, number);
            history.push_back(data);
        }
    }

    // Delete an element at a specified index in the list
    void deleteAtIndex(int index) {
        if (index < data.size()) {
            list<int>::iterator it = data.begin();
            advance(it, index);
            if (it == cursor) {
                cursor = data.begin();
            }
            data.erase(it);
            history.push_back(data);
        }
    }

    // Move the cursor forward by a specified number of steps
    void moveForward(int steps) {
        for (int i = 0; i < steps && cursor != data.end(); i++) {
            cursor++;
        }
    }

    // Move the cursor backward by a specified number of steps
    void moveBackward(int steps) {
        for (int i = 0; i < steps && cursor != data.begin(); i++) {
            cursor--;
        }
    }

    // Insert a number immediately before the cursor position
    void addImmediate(int number) {
        if (!data.empty()) {
            data.insert(cursor, number);
            history.push_back(data);
        } else {
            addNumber(number);
        }
    }

    // Delete the element at the cursor position
    void deleteImmediate() {
        if (!data.empty()) {
            cursor = data.erase(cursor);
            history.push_back(data);
        }
    }

    // Print the current state of the list
    void print() {
        if (!data.empty()) {
            cout << "List: [";
            for (list<int>::iterator it = data.begin(); it != data.end(); ++it) {
                if (it != data.begin()) {
                    cout << ", ";
                }
                cout << *it;
            }
            cout << "]" << endl;
        } else {
            cout << "List: []" << endl;
        }
    }

    // Update the value at a specified index in the list
    void updateAtIndex(int index, int number) {
        if (index < data.size()) {
            list<int>::iterator it = data.begin();
            advance(it, index);
            *it = number;
            history.push_back(data);
        }
    }

    // Update the value at the cursor position
    void updateImmediate(int number) {
        if (!data.empty()) {
            *cursor = number;
            history.push_back(data);
        }
    }

    // Swap the element at the cursor position with the element at a specified index
    void shift(int index) {
        if (index < data.size()) {
            list<int>::iterator it = data.begin();
            advance(it, index);
            swap(*cursor, *it);
            history.push_back(data);
        }
    }

    // Undo the last operation by reverting to the previous state in the history
    void undo() {
        if (!history.empty()) {
            history.pop_back();
            if (!history.empty()) {
                data = history.back();
                cursor = data.begin();
            } else {
                data.clear();
                cursor = data.begin();
            }
        }
    }
};

// Main function to read and execute commands from a text file
int main() {
    Editor editor;
    ifstream file("C:/Users/sg/Desktop/Q4/t1.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string command;
            ss >> command;

            // Execute various commands based on the command keyword
            if (command == "Add") {
                int number;
                ss >> number;
                editor.addNumber(number);
            } else if (command == "Delete") {
                editor.deleteTail();
            } else if (command == "AddImmediate") {
                int number;
                ss >> number;
                editor.addImmediate(number);
            } else if (command == "DeleteImmediate") {
                editor.deleteImmediate();
            } else if (command == "Print") {
                editor.print();
            } else if (command == "MoveForward") {
                int steps;
                ss >> steps;
                editor.moveForward(steps);
                cout << "Cursor moved forward by " << steps << " step(s)." << endl;
            } else if (command == "MoveBackward") {
                int steps;
                ss >> steps;
                editor.moveBackward(steps);
                cout << "Cursor moved backward by " << steps << " step(s)." << endl;
            } else if (command == "Update") {
                int index, number;
                ss >> index >> number;
                editor.updateAtIndex(index, number);
            } else if (command == "UpdateImmediate") {
                int number;
                ss >> number;
                editor.updateImmediate(number);
            } else if (command == "Shift") {
                int index;
                ss >> index;
                editor.shift(index);
            } else if (command == "Undo") {
                editor.undo();
            }
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }

    return 0;
}




#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> myDictionary; // Declaration of dictionary to store key-value pairs

    int choice;
    string key, value;

    do {
        // Display menu
        cout << "\nDictionary Operations Menu:" << endl;
        cout << "1. Add Key-Value Pair" << endl;
        cout << "2. Display Dictionary" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add key-value pair to the dictionary
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                myDictionary[key] = value;
                cout << "Key-Value Pair added to the dictionary." << endl;
                break;

            case 2:
                // Display elements of the dictionary
                cout << "Dictionary Elements:" << endl;
                for (const auto &entry : myDictionary) {
                    cout << entry.first << ": " << entry.second << endl;
                }
                break;

            case 3:
                // Exit the program
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 3);

    return 0;
}

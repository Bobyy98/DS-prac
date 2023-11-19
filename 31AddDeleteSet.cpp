#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> mySet; // Declaration of set to store integers

    int choice, element;

    do {
        // Display menu
        cout << "\nSet Operations Menu:" << endl;
        cout << "1. Add Element" << endl;
        cout << "2. Remove Element" << endl;
        cout << "3. Display Set" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Add element to the set
                cout << "Enter the element to add: ";
                cin >> element;
                mySet.insert(element);
                cout << "Element added to the set." << endl;
                break;

            case 2:
                // Remove element from the set
                cout << "Enter the element to remove: ";
                cin >> element;
                if (mySet.erase(element) > 0) {
                    cout << "Element removed from the set." << endl;
                } else {
                    cout << "Element not found in the set." << endl;
                }
                break;

            case 3:
                // Display elements of the set
                cout << "Set Elements: ";
                for (const auto &e : mySet) {
                    cout << e << " ";
                }
                cout << endl;
                break;

            case 4:
                // Exit the program
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 4);

    return 0;
}

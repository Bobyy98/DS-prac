#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the circular doubly linked list
struct Node* insertNode(struct Node* last, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = last->next;
    new_node->prev = last;
    last->next->prev = new_node;
    last->next = new_node;
    return new_node;
}

// Function to count the number of nodes in the circular doubly linked list
int countNodes(struct Node* last) {
    if (last == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* temp = last->next;

    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);

    return count;
}

// Function to display the nodes in the circular doubly linked list
void displayNodes(struct Node* last) {
    if (last == NULL) {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    struct Node* temp = last->next;

    printf("Nodes in the circular doubly linked list: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

// Function to display the menu
void displayMenu() {
    printf("\n\n---- Circular Doubly Linked List Operations ----\n");
    printf("1. Insert a node\n");
    printf("2. Count the number of nodes\n");
    printf("3. Display nodes\n");
    printf("4. Exit\n");
}

int main() {
    struct Node* last = NULL;
    int choice, data;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                if (last == NULL) {
                    last = (struct Node*)malloc(sizeof(struct Node));
                    last->data = data;
                    last->next = last;
                    last->prev = last;
                } else {
                    last = insertNode(last, data);
                }
                printf("Node inserted successfully!\n");
                break;

            case 2:
                printf("Number of nodes in the circular doubly linked list: %d\n", countNodes(last));
                break;

            case 3:
                displayNodes(last);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free allocated memory before exiting
    struct Node* temp = last;
    if (temp != NULL) {
        do {
            struct Node* next_node = temp->next;
            free(temp);
            temp = next_node;
        } while (temp != last);
    }

    return 0;
}

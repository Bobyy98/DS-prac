#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to count the number of nodes in the linked list
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to insert a new node at the end of the linked list
struct Node* insertNode(struct Node *head, int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Function to display nodes in the linked list
void displayNodes(struct Node *head) {
    struct Node *current = head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to display the menu options
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Count nodes\n");
    printf("3. Display nodes\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    struct Node *head = NULL;
    int choice, value;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertNode(head, value);
                break;
            case 2:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 3:
                displayNodes(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free the allocated memory for the linked list
    struct Node *current = head;
    struct Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

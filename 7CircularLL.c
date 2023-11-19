#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertNode(struct Node** head, int value);
void deleteNode(struct Node** head, int value);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        // Menu
        printf("\nCircular Linked List Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert Node
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                break;

            case 2:
                // Delete Node
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 3:
                // Display List
                displayList(head);
                break;

            case 4:
                // Exit
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

// Function to insert a node at the end of the circular linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;

    if (*head == NULL) {
        // If the list is empty, make the new node the head
        *head = newNode;
        newNode->next = *head;
    } else {
        // Traverse to the last node and update the next pointer
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Node inserted successfully!\n");
}

// Function to delete a node with a specific value from the circular linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from an empty list.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    // Find the node to delete and keep track of the previous node
    while (current->data != value) {
        if (current->next == *head) {
            printf("Node with value %d not found in the list.\n", value);
            return;
        }
        prev = current;
        current = current->next;
    }

    // If the node to delete is the only node in the list
    if (current == *head && current->next == *head) {
        *head = NULL;
    } else if (current == *head) {
        // If the node to delete is the head of the list
        prev = *head;
        while (prev->next != *head) {
            prev = prev->next;
        }
        *head = current->next;
        prev->next = *head;
    } else {
        // If the node to delete is in the middle or end of the list
        prev->next = current->next;
    }

    free(current);
    printf("Node with value %d deleted successfully!\n", value);
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    printf("Circular Linked List: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

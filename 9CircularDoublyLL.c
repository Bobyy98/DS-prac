#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
void insertAtBeginning(struct Node** head, int value);
void insertAtEnd(struct Node** head, int value);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        // Display menu
        printf("\nCircular Doubly Linked List Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to insert a node at the beginning of the circular doubly linked list
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the only node in the list
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        // Otherwise, insert the new node at the beginning
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }

    printf("Node with value %d inserted at the beginning.\n", value);
}

// Function to insert a node at the end of the circular doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        // If the list is empty, make the new node the only node in the list
        *head = newNode;
        (*head)->next = *head;
        (*head)->prev = *head;
    } else {
        // Otherwise, insert the new node at the end
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }

    printf("Node with value %d inserted at the end.\n", value);
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;

    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

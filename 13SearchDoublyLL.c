#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the doubly linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to search for a number in the doubly linked list
int searchNumber(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return 1; // Found
        }
        head = head->next;
    }
    return 0; // Not found
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, number, result;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert a number into the doubly linked list\n");
        printf("2. Search for a number\n");
        printf("3. Display the doubly linked list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number to insert: ");
                scanf("%d", &number);
                insertNode(&head, number);
                break;

            case 2:
                printf("Enter a number to search: ");
                scanf("%d", &number);
                result = searchNumber(head, number);
                if (result) {
                    printf("%d found in the doubly linked list.\n", number);
                } else {
                    printf("%d not found in the doubly linked list.\n", number);
                }
                break;

            case 3:
                displayList(head);
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free the allocated memory before exiting
    struct Node* current = head;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

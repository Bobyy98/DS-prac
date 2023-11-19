#include <stdio.h>
#include <stdlib.h>

// Node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the circular linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for a number in the circular linked list
int searchNumber(struct Node* head, int key) {
    struct Node* current = head;

    if (head == NULL) {
        return 0; // Not found
    }

    do {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    } while (current != head);

    return 0; // Not found
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    struct Node* current = head;

    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(head)\n");
}

int main() {
    struct Node* head = NULL;
    int choice, number, result;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert a number into the circular linked list\n");
        printf("2. Search for a number\n");
        printf("3. Display the circular linked list\n");
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
                    printf("%d found in the circular linked list.\n", number);
                } else {
                    printf("%d not found in the circular linked list.\n", number);
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
    if (head != NULL) {
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to delete a node from the beginning of the linked list
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the beginning.\n");
        return NULL;
    }
    struct Node* newHead = head->next;
    free(head);
    return newHead;
}

// Function to delete a node from the middle of the linked list
struct Node* deleteFromMiddle(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the middle.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 0;

    while (current != NULL && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Position exceeds the length of the list. Cannot delete from the middle.\n");
        return head;
    }

    if (previous == NULL) {
        // Deleting the first node
        head = current->next;
    } else {
        // Deleting a node in the middle
        previous->next = current->next;
    }

    free(current);
    return head;
}

// Function to delete a node from the end of the linked list
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from the end.\n");
        return NULL;
    }

    if (head->next == NULL) {
        // Only one node in the list
        free(head);
        return NULL;
    }

    struct Node* current = head;
    struct Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    // Deleting the last node
    free(current);
    previous->next = NULL;

    return head;
}

// Function to free the entire linked list
void freeList(struct Node* head) {
    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\n----- Singly Linked List Menu -----\n");
        printf("1. Insert at the beginning\n");
        printf("2. Delete from the beginning\n");
        printf("3. Delete from the middle\n");
        printf("4. Delete from the end\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                head = deleteFromBeginning(head);
                break;
            case 3:
                printf("Enter the position to delete from the middle: ");
                scanf("%d", &position);
                head = deleteFromMiddle(head, position - 1); // Position is 1-based
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    // Free the allocated memory before exiting
    freeList(head);

    return 0;
}

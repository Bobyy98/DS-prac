#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the end of the doubly linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        // If the list is empty, the new node is the first and last node
        newNode->prev = NULL;
        *head = newNode;
    } else {
        // Otherwise, add the new node to the end of the list
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Node with value %d inserted.\n", value);
}

// Function to delete a node with a given value from the doubly linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Doubly linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node *current, *prev;
    current = *head;
    prev = NULL;

    // Traverse the doubly linked list to find the node to delete
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (prev == NULL) {
        // If the node to be deleted is the first node
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = prev;
        }
    }

    free(current);
    printf("Node with value %d deleted.\n", value);
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(&head, value);
                break;

            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
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

    // Free memory before exiting
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the end of the circular doubly linked list
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        newNode->prev = *head;
    } else {
        struct Node* temp = (*head)->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = *head;
        (*head)->prev = newNode;
    }

    printf("Node with value %d inserted.\n", value);
}

// Function to delete a node with a given value from the circular doubly linked list
void deleteNode(struct Node** head, int value) {
    if (*head == NULL) {
        printf("Circular doubly linked list is empty. Cannot delete.\n");
        return;
    }

    struct Node *current, *prev;
    current = *head;
    prev = NULL;

    // Traverse the circular doubly linked list to find the node to delete
    do {
        if (current->data == value) {
            if (prev == NULL) {
                // If the node to be deleted is the first node
                if (current->next == *head) {
                    // If there is only one node in the circular doubly linked list
                    free(current);
                    *head = NULL;
                } else {
                    struct Node* tempPrev = current->prev;
                    struct Node* tempNext = current->next;
                    tempPrev->next = tempNext;
                    tempNext->prev = tempPrev;
                    if (current == *head) {
                        *head = tempNext;
                    }
                    free(current);
                }
            } else {
                struct Node* tempPrev = current->prev;
                struct Node* tempNext = current->next;
                tempPrev->next = tempNext;
                tempNext->prev = tempPrev;
                free(current);
            }

            printf("Node with value %d deleted.\n", value);
            return;
        }

        prev = current;
        current = current->next;
    } while (current != *head);

    printf("Node with value %d not found.\n", value);
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("Circular doubly linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
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

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node at the end of the doubly linked list
struct Node* insertNode(struct Node* head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

// Function to count the number of nodes in the doubly linked list
int countNodes(struct Node* head) {
    if (head == NULL) {
        return 0;
    }

    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

// Function to display the nodes in the doubly linked list
void displayNodes(struct Node* head) {
    if (head == NULL) {
        printf("Doubly linked list is empty.\n");
        return;
    }

    struct Node* temp = head;

    printf("Nodes in the doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to display the menu
void displayMenu() {
    printf("\n\n---- Doubly Linked List Operations ----\n");
    printf("1. Insert a node\n");
    printf("2. Count the number of nodes\n");
    printf("3. Display nodes\n");
    printf("4. Exit\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertNode(head, data);
                printf("Node inserted successfully!\n");
                break;

            case 2:
                printf("Number of nodes in the doubly linked list: %d\n", countNodes(head));
                break;

            case 3:
                displayNodes(head);
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free allocated memory before exiting
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next_node = temp->next;
        free(temp);
        temp = next_node;
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if memory allocation is successful
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack overflow.\n");
        return;
    }

    // Set the data and next pointer of the new node
    newNode->data = value;
    newNode->next = *top;

    // Update the top to point to the new node
    *top = newNode;

    printf("%d pushed onto the stack.\n", value);
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL; // Initialize an empty stack
    int choice, value;

    do {
        // Display menu
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Push operation
                printf("Enter the value to push onto the stack: ");
                scanf("%d", &value);
                push(&top, value);
                break;
            case 2:
                // Display operation
                display(top);
                break;
            case 3:
                // Exit the program
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    // Free the allocated memory for the nodes before exiting
    while (top != NULL) {
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }

    return 0;
}

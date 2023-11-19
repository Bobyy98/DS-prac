#include <stdio.h>
#define MAX_SIZE 10

// Function to push an element onto the stack
void push(int stack[], int *top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push element.\n");
    } else {
        (*top)++;
        stack[*top] = value;
        printf("Element %d pushed onto the stack.\n", value);
    }
}

// Function to display the current elements of the stack
void display(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int stack[MAX_SIZE];
    int top = -1;  // Initialize top of stack to -1

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
                printf("Enter the element to push onto the stack: ");
                scanf("%d", &value);
                push(stack, &top, value);
                break;

            case 2:
                // Display operation
                display(stack, top);
                break;

            case 3:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

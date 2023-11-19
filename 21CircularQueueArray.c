#include <stdio.h>

#define MAX_SIZE 5

int circularQueue[MAX_SIZE];
int front = -1, rear = -1;

// Function prototypes
void insertElement(int element);
void deleteElement();
void displayQueue();
int isFull();
int isEmpty();

int main() {
    int choice, element;

    do {
        printf("\nCircular Queue Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(element);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

void insertElement(int element) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        circularQueue[rear] = element;
        printf("Element %d inserted successfully.\n", element);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
    } else {
        int deletedElement = circularQueue[front];
        if (front == rear) {
            // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Element %d deleted successfully.\n", deletedElement);
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Circular Queue elements: ");
        int i = front;
        do {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int isFull() {
    return (front == (rear + 1) % MAX_SIZE);
}

int isEmpty() {
    return (front == -1);
}

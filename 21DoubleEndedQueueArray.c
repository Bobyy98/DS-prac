#include <stdio.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1, rear = -1;

// Function prototypes
void insertFront(int element);
void insertRear(int element);
void deleteFront();
void deleteRear();
void displayDeque();
int isFull();
int isEmpty();

int main() {
    int choice, element;

    do {
        printf("\nDouble-Ended Queue (Deque) Menu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the front: ");
                scanf("%d", &element);
                insertFront(element);
                break;
            case 2:
                printf("Enter the element to insert at the rear: ");
                scanf("%d", &element);
                insertRear(element);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                displayDeque();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

void insertFront(int element) {
    if (isFull()) {
        printf("Deque is full. Cannot insert element at the front.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        deque[front] = element;
        printf("Element %d inserted at the front successfully.\n", element);
    }
}

void insertRear(int element) {
    if (isFull()) {
        printf("Deque is full. Cannot insert element at the rear.\n");
    } else {
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        deque[rear] = element;
        printf("Element %d inserted at the rear successfully.\n", element);
    }
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete element from the front.\n");
    } else {
        printf("Deleted element from the front: %d\n", deque[front]);
        if (front == rear) {
            // Only one element in the deque
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty. Cannot delete element from the rear.\n");
    } else {
        printf("Deleted element from the rear: %d\n", deque[rear]);
        if (front == rear) {
            // Only one element in the deque
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX_SIZE - 1;
        } else {
            rear--;
        }
    }
}

void displayDeque() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = front;
        do {
            printf("%d ", deque[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int isFull() {
    return ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1));
}

int isEmpty() {
    return (front == -1);
}

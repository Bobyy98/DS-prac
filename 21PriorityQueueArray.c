#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int data;
    int priority;
} QueueElement;

QueueElement priorityQueue[MAX_SIZE];
int rear = -1;

// Function prototypes
void insertElement(int data, int priority);
void deleteElement();
void displayQueue();
int isFull();
int isEmpty();

int main() {
    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the priority (an integer): ");
                scanf("%d", &priority);
                insertElement(data, priority);
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

void insertElement(int data, int priority) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        int i;
        for (i = rear; i >= 0 && priorityQueue[i].priority > priority; i--) {
            priorityQueue[i + 1] = priorityQueue[i];
        }
        priorityQueue[i + 1].data = data;
        priorityQueue[i + 1].priority = priority;
        rear++;
        printf("Element %d with priority %d inserted successfully.\n", data, priority);
    }
}

void deleteElement() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete element.\n");
    } else {
        printf("Deleted element: Data=%d, Priority=%d\n", priorityQueue[rear].data, priorityQueue[rear].priority);
        rear--;
    }
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Priority Queue elements: ");
        for (int i = 0; i <= rear; i++) {
            printf("(Data=%d, Priority=%d) ", priorityQueue[i].data, priorityQueue[i].priority);
        }
        printf("\n");
    }
}

int isFull() {
    return (rear == MAX_SIZE - 1);
}

int isEmpty() {
    return (rear == -1);
}

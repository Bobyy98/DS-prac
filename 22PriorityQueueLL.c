#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Priority Queue structure
struct PriorityQueue {
    struct Node* front;
};

// Function prototypes
void initializeQueue(struct PriorityQueue* queue);
void enqueue(struct PriorityQueue* queue, int data, int priority);
int dequeue(struct PriorityQueue* queue);
void displayQueue(struct PriorityQueue* queue);

// Main function with menu-driven operations
int main() {
    struct PriorityQueue queue;
    initializeQueue(&queue);

    int choice, data, priority;

    do {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue: ");
                scanf("%d", &data);
                printf("Enter the priority: ");
                scanf("%d", &priority);
                enqueue(&queue, data, priority);
                break;
            case 2:
                if (queue.front == NULL) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    printf("Dequeued element: %d\n", dequeue(&queue));
                }
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the priority queue
void initializeQueue(struct PriorityQueue* queue) {
    queue->front = NULL;
}

// Function to enqueue a data element with priority
void enqueue(struct PriorityQueue* queue, int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (queue->front == NULL || priority < queue->front->priority) {
        // If the queue is empty or the new node has higher priority,
        // insert at the beginning
        newNode->next = queue->front;
        queue->front = newNode;
    } else {
        // Traverse the queue to find the appropriate position
        struct Node* current = queue->front;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }

        // Insert the new node at the correct position
        newNode->next = current->next;
        current->next = newNode;
    }

    printf("Enqueued %d with priority %d successfully.\n", data, priority);
}

// Function to dequeue an element with the highest priority
int dequeue(struct PriorityQueue* queue) {
    int dequeuedData;
    struct Node* temp;

    // Store the data to be dequeued
    dequeuedData = queue->front->data;

    // Move front to the next node and free the previous front
    temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    return dequeuedData;
}

// Function to display the elements in the priority queue
void displayQueue(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = queue->front;
        printf("Priority Queue elements:\n");
        while (current != NULL) {
            printf("Data: %d, Priority: %d\n", current->data, current->priority);
            current = current->next;
        }
    }
}

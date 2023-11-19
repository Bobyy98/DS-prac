#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Circular Queue structure
struct CircularQueue {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeQueue(struct CircularQueue* queue);
void enqueue(struct CircularQueue* queue, int data);
int dequeue(struct CircularQueue* queue);
void displayQueue(struct CircularQueue* queue);

// Main function with menu-driven operations
int main() {
    struct CircularQueue queue;
    initializeQueue(&queue);

    int choice, data;

    do {
        printf("\nCircular Queue Menu:\n");
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
                enqueue(&queue, data);
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

// Function to initialize the circular queue
void initializeQueue(struct CircularQueue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Function to enqueue a data element
void enqueue(struct CircularQueue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->front == NULL) {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    // Make the queue circular by connecting the rear to the front
    queue->rear->next = queue->front;

    printf("Enqueued %d successfully.\n", data);
}

// Function to dequeue an element
int dequeue(struct CircularQueue* queue) {
    int dequeuedData;
    struct Node* temp;

    // Store the data to be dequeued
    dequeuedData = queue->front->data;

    // If there's only one element in the queue
    if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
    } else {
        // Move front to the next node and free the previous front
        temp = queue->front;
        queue->front = queue->front->next;
        free(temp);

        // Make the queue circular again by connecting the rear to the new front
        queue->rear->next = queue->front;
    }

    return dequeuedData;
}

// Function to display the elements in the queue
void displayQueue(struct CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Node* current = queue->front;
        printf("Queue elements: ");
        do {
            printf("%d ", current->data);
            current = current->next;
        } while (current != queue->front);
        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Double-ended Queue structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function prototypes
void initializeDeque(struct Deque* deque);
void enqueueFront(struct Deque* deque, int data);
void enqueueRear(struct Deque* deque, int data);
int dequeueFront(struct Deque* deque);
int dequeueRear(struct Deque* deque);
void displayDeque(struct Deque* deque);

// Main function with menu-driven operations
int main() {
    struct Deque deque;
    initializeDeque(&deque);

    int choice, data;

    do {
        printf("\nDouble-ended Queue (Deque) Menu:\n");
        printf("1. Enqueue Front\n");
        printf("2. Enqueue Rear\n");
        printf("3. Dequeue Front\n");
        printf("4. Dequeue Rear\n");
        printf("5. Display Deque\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to enqueue at the front: ");
                scanf("%d", &data);
                enqueueFront(&deque, data);
                break;
            case 2:
                printf("Enter the data to enqueue at the rear: ");
                scanf("%d", &data);
                enqueueRear(&deque, data);
                break;
            case 3:
                if (deque.front == NULL) {
                    printf("Deque is empty. Cannot dequeue from front.\n");
                } else {
                    printf("Dequeued element from front: %d\n", dequeueFront(&deque));
                }
                break;
            case 4:
                if (deque.rear == NULL) {
                    printf("Deque is empty. Cannot dequeue from rear.\n");
                } else {
                    printf("Dequeued element from rear: %d\n", dequeueRear(&deque));
                }
                break;
            case 5:
                displayDeque(&deque);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to initialize the double-ended queue
void initializeDeque(struct Deque* deque) {
    deque->front = NULL;
    deque->rear = NULL;
}

// Function to enqueue a data element at the front of the deque
void enqueueFront(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if (deque->front == NULL) {
        // If the deque is empty, set both front and rear to the new node
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        // Otherwise, update the previous pointer of the current front
        deque->front->prev = newNode;
        // Update the front pointer to the new node
        deque->front = newNode;
    }

    printf("Enqueued %d at the front successfully.\n", data);
}

// Function to enqueue a data element at the rear of the deque
void enqueueRear(struct Deque* deque, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if (deque->rear == NULL) {
        // If the deque is empty, set both front and rear to the new node
        deque->front = newNode;
        deque->rear = newNode;
    } else {
        // Otherwise, update the next pointer of the current rear
        deque->rear->next = newNode;
        // Update the rear pointer to the new node
        deque->rear = newNode;
    }

    printf("Enqueued %d at the rear successfully.\n", data);
}

// Function to dequeue an element from the front of the deque
int dequeueFront(struct Deque* deque) {
    int dequeuedData;
    struct Node* temp;

    // Store the data to be dequeued
    dequeuedData = deque->front->data;

    // If there's only one element in the deque
    if (deque->front == deque->rear) {
        free(deque->front);
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        // Move front to the next node and free the previous front
        temp = deque->front;
        deque->front = deque->front->next;
        deque->front->prev = NULL;
        free(temp);
    }

    return dequeuedData;
}

// Function to dequeue an element from the rear of the deque
int dequeueRear(struct Deque* deque) {
    int dequeuedData;
    struct Node* temp;

    // Store the data to be dequeued
    dequeuedData = deque->rear->data;

    // If there's only one element in the deque
    if (deque->front == deque->rear) {
        free(deque->rear);
        deque->front = NULL;
        deque->rear = NULL;
    } else {
        // Move rear to the previous node and free the previous rear
        temp = deque->rear;
        deque->rear = deque->rear->prev;
        deque->rear->next = NULL;
        free(temp);
    }

    return dequeuedData;
}

// Function to display the elements in the deque
void displayDeque(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Deque is empty.\n");
    } else {
        struct Node* current = deque->front;
        printf("Deque elements from front to rear:\n");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

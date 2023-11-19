#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to count nodes in the BST
int countNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// Function to display nodes in the BST (in-order traversal)
void displayNodes(struct Node* root) {
    if (root != NULL) {
        displayNodes(root->left);
        printf("%d ", root->data);
        displayNodes(root->right);
    }
}

// Function to free the memory allocated for the tree
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, n, data;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Count nodes\n");
        printf("3. Display nodes\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a node
                printf("Enter the value of the node: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                // Count nodes
                printf("Number of nodes in the Binary Search Tree: %d\n", countNodes(root));
                break;

            case 3:
                // Display nodes
                printf("Nodes in the Binary Search Tree (in-order traversal): ");
                displayNodes(root);
                printf("\n");
                break;

            case 4:
                // Exit
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Freeing the allocated memory for the tree
    freeTree(root);

    return 0;
}

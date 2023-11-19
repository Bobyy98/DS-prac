#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the BST
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

// Function to insert a value into the BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the largest node in the BST
struct Node* findLargest(struct Node* root) {
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes in the BST: ");
    scanf("%d", &n);

    printf("Enter the values for the BST nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    struct Node* largestNode = findLargest(root);

    if (largestNode != NULL) {
        printf("The largest node in the BST is: %d\n", largestNode->data);
    } else {
        printf("The BST is empty.\n");
    }

    // Free the allocated memory for the BST (optional)
    // Note: In a real-world scenario, you would want to implement a proper deallocation function.
    // Here, we are not deallocating memory for simplicity.

    return 0;
}

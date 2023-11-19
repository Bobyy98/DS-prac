#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
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

// Function to find the smallest node in the BST
struct Node* findSmallestNode(struct Node* root) {
    struct Node* current = root;

    // Traverse to the leftmost node
    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of elements in the BST: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    // Find the smallest node in the BST
    struct Node* smallestNode = findSmallestNode(root);

    // Display the smallest node value
    printf("The smallest node in the BST is: %d\n", smallestNode->data);

    return 0;
}

#include <stdio.h>

// Function to display the array elements
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert a number at a given location in the array
void insertNumber(int arr[], int *size, int location, int number) {
    if (location < 0 || location > *size) {
        printf("Invalid location for insertion.\n");
        return;
    }

    // Shift elements to make space for the new number
    for (int i = *size; i > location; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the number at the specified location
    arr[location] = number;

    // Increase the size of the array
    (*size)++;

    printf("Number %d inserted at location %d.\n", number, location);
}

// Function to delete a number from a given location in the array
void deleteNumber(int arr[], int *size, int location) {
    if (location < 0 || location >= *size) {
        printf("Invalid location for deletion.\n");
        return;
    }

    // Shift elements to fill the gap left by the deleted number
    for (int i = location; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrease the size of the array
    (*size)--;

    printf("Number deleted from location %d.\n", location);
}

int main() {
    int arr[100], size = 0;
    int choice, location, number;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Array\n");
        printf("2. Insert Number\n");
        printf("3. Delete Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter the location to insert: ");
                scanf("%d", &location);
                printf("Enter the number to insert: ");
                scanf("%d", &number);
                insertNumber(arr, &size, location, number);
                break;
            case 3:
                printf("Enter the location to delete: ");
                scanf("%d", &location);
                deleteNumber(arr, &size, location);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

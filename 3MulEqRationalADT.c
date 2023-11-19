#include <stdio.h>

// Structure to represent a rational number
typedef struct {
    int numerator;
    int denominator;
} Rational;

// Function to get input for a rational number
Rational getRational() {
    Rational num;
    printf("Enter numerator: ");
    scanf("%d", &num.numerator);
    printf("Enter denominator: ");
    scanf("%d", &num.denominator);
    return num;
}

// Function to perform multiplication of two rational numbers
Rational multiply(Rational num1, Rational num2) {
    Rational result;
    result.numerator = num1.numerator * num2.numerator;
    result.denominator = num1.denominator * num2.denominator;
    return result;
}

// Function to check equality of two rational numbers
int isEqual(Rational num1, Rational num2) {
    return (num1.numerator * num2.denominator) == (num2.numerator * num1.denominator);
}

int main() {
    int choice;
    Rational num1, num2, result;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Input first rational number\n");
        printf("2. Input second rational number\n");
        printf("3. Multiply\n");
        printf("4. Check equality\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input first rational number
                printf("Enter the first rational number:\n");
                num1 = getRational();
                break;

            case 2:
                // Input second rational number
                printf("Enter the second rational number:\n");
                num2 = getRational();
                break;

            case 3:
                // Multiply and display the result
                result = multiply(num1, num2);
                printf("Result of multiplication: %d / %d\n", result.numerator, result.denominator);
                break;

            case 4:
                // Check equality and display the result
                if (isEqual(num1, num2)) {
                    printf("The two rational numbers are equal.\n");
                } else {
                    printf("The two rational numbers are not equal.\n");
                }
                break;

            case 0:
                // Exit the program
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

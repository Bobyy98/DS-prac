#include <stdio.h>

// Structure to represent a rational number
typedef struct {
    int numerator;
    int denominator;
} Rational;

// Function to find the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to simplify a rational number
void simplify(Rational *r) {
    int commonDivisor = gcd(r->numerator, r->denominator);
    r->numerator /= commonDivisor;
    r->denominator /= commonDivisor;
}

// Function to add two rational numbers
Rational add(Rational a, Rational b) {
    Rational result;
    result.numerator = (a.numerator * b.denominator) + (b.numerator * a.denominator);
    result.denominator = a.denominator * b.denominator;
    simplify(&result);
    return result;
}

// Function to subtract two rational numbers
Rational subtract(Rational a, Rational b) {
    Rational result;
    result.numerator = (a.numerator * b.denominator) - (b.numerator * a.denominator);
    result.denominator = a.denominator * b.denominator;
    simplify(&result);
    return result;
}

int main() {
    Rational num1, num2;
    int choice = 0;
    int enteredNumbers = 0; // Flag to track whether the user has entered rational numbers

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Enter rational numbers\n");
        printf("2. Add\n");
        printf("3. Subtract\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Input for the first rational number
                printf("Enter the numerator for the first rational number: ");
                scanf("%d", &num1.numerator);

                printf("Enter the denominator for the first rational number: ");
                scanf("%d", &num1.denominator);

                // Input for the second rational number
                printf("Enter the numerator for the second rational number: ");
                scanf("%d", &num2.numerator);

                printf("Enter the denominator for the second rational number: ");
                scanf("%d", &num2.denominator);

                enteredNumbers = 1; // Set the flag to true after entering numbers
                break;

            case 2:
                // Addition
                if (!enteredNumbers) {
                    printf("Please enter rational numbers first.\n");
                } else {
                    Rational sum = add(num1, num2);
                    printf("Sum: %d/%d\n", sum.numerator, sum.denominator);
                }
                break;

            case 3:
                // Subtraction
                if (!enteredNumbers) {
                    printf("Please enter rational numbers first.\n");
                } else {
                    Rational difference = subtract(num1, num2);
                    printf("Difference: %d/%d\n", difference.numerator, difference.denominator);
                }
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

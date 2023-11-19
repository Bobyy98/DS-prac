#include <stdio.h>

// Define the complex number ADT
typedef struct {
    float real;
    float imag;
} Complex;

// Function prototypes
Complex multiply(Complex num1, Complex num2);
int isEqual(Complex num1, Complex num2);

int main() {
    // Declare variables
    Complex num1, num2, result;
    int choice;

    // Get user input for complex numbers
    printf("Enter the first complex number (a + bi):\n");
    printf("Real part (a): ");
    scanf("%f", &num1.real);
    printf("Imaginary part (b): ");
    scanf("%f", &num1.imag);

    printf("\nEnter the second complex number (c + di):\n");
    printf("Real part (c): ");
    scanf("%f", &num2.real);
    printf("Imaginary part (d): ");
    scanf("%f", &num2.imag);

    // Menu-driven operations
    printf("\nMenu:\n");
    printf("1. Multiply complex numbers\n");
    printf("2. Check equality of complex numbers\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Multiply complex numbers
            result = multiply(num1, num2);
            printf("Result of multiplication: %.2f + %.2fi\n", result.real, result.imag);
            break;

        case 2:
            // Check equality of complex numbers
            if (isEqual(num1, num2)) {
                printf("Complex numbers are equal.\n");
            } else {
                printf("Complex numbers are not equal.\n");
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;
    }

    return 0;
}

// Function to multiply two complex numbers
Complex multiply(Complex num1, Complex num2) {
    Complex result;
    result.real = (num1.real * num2.real) - (num1.imag * num2.imag);
    result.imag = (num1.real * num2.imag) + (num1.imag * num2.real);
    return result;
}

// Function to check equality of two complex numbers
int isEqual(Complex num1, Complex num2) {
    return (num1.real == num2.real) && (num1.imag == num2.imag);
}

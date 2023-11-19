#include <stdio.h>

// Define the complex number structure
typedef struct {
    float real;
    float imag;
} Complex;

// Function to add two complex numbers
Complex add(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imag = num1.imag + num2.imag;
    return result;
}

// Function to subtract two complex numbers
Complex subtract(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.imag = num1.imag - num2.imag;
    return result;
}

int main() {
    Complex num1, num2, result;
    int choice;

    // User input for the first complex number
    printf("Enter the real and imaginary parts of the first complex number:\n");
    printf("Real: ");
    scanf("%f", &num1.real);
    printf("Imaginary: ");
    scanf("%f", &num1.imag);

    // User input for the second complex number
    printf("\nEnter the real and imaginary parts of the second complex number:\n");
    printf("Real: ");
    scanf("%f", &num2.real);
    printf("Imaginary: ");
    scanf("%f", &num2.imag);

    // Menu-driven operation selection
    printf("\nMenu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    // Perform the selected operation
    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("\nResult of addition: %.2f + %.2fi\n", result.real, result.imag);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("\nResult of subtraction: %.2f + %.2fi\n", result.real, result.imag);
            break;
        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}

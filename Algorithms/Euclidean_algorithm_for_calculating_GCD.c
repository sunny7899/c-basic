#include <stdio.h>

// Function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;  // Update b to the remainder of a divided by b
        a = temp;   // Update a to the previous value of b
    }
    return a;  // The GCD is stored in a
}

int main() {
    int num1, num2;

    // Input two integers from the user
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Ensure that the input numbers are non-negative
    if (num1 < 0 || num2 < 0) {
        printf("Please enter non-negative integers.\n");
        return 1; // Exit the program with an error code
    }

    // Calculate and display the GCD
    printf("The GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));

    return 0; // Exit the program successfully
}

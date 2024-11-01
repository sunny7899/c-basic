#include <stdio.h>

/*
 * This program generates the Fibonacci sequence up to a specified number of terms.
 * The Fibonacci sequence starts with 0 and 1, and each subsequent number is the sum 
 * of the two preceding ones. The user is prompted to enter how many terms they want 
 * to see, and the program displays the sequence accordingly.
 */

int main() {
    int n, first = 0, second = 1, next;

    // Ask the user for the number of terms in the Fibonacci sequence
    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence:\n");

    // Generate and print the Fibonacci sequence
    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            next = i; // For the first two terms, just output i
        } else {
            next = first + second; // Calculate the next term
            first = second; // Update first to the last term
            second = next; // Update second to the current term
        }
        printf("%d ", next); // Print the current term
    }

    printf("\n"); // New line after the sequence
    return 0; // End of the program
}

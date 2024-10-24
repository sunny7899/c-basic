#include <stdio.h>
#include <float.h>

int main() {
    char operator;
    double num1, num2, result;

    // Prompt user to input operator
    printf("Select an operator (+, -, *, /): ");
    scanf(" %c", &operator);  // Added space to handle newline character

    // Request user input for two operands
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    
    // Perform operation based on the selected operator
    switch (operator) {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            printf("Error! Division by zero.\n");
            return 1;
        }
        break;
    default:
        printf("Invalid operator!\n");
        return 1;
    }

    // Output the result
    printf("Result: %.2lf\n", result);
    
    return 0;
}

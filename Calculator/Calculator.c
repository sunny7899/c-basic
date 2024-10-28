#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to add two numbers
void addNumbers(double a, double b)
{
    printf("%lf + %lf = %lf\n", a, b, a + b);
}

// Function to subtract the second number from the first
void subNumbers(double a, double b)
{
    printf("%lf - %lf = %lf\n", a, b, a - b);
}

// Function to multiply two numbers
void multiplyNumbers(double a, double b)
{
    printf("%lf x %lf = %lf\n", a, b, a * b);
}

// Function to divide the first number by the second
void divideNumbers(double a, double b)
{
    if (b != 0)
    {
        printf("%lf / %lf = %lf\n", a, b, a / b);
    }
    else
    {
        printf("Error! Division by zero is not allowed.\n");
    }
}

// Function to calculate the square of a number
void squareNumber(double a)
{
    printf("%lf^2 = %lf\n", a, a * a);
}

// Function to calculate the square root of a number
void sqrtNumber(double a)
{
    if (a >= 0)
    {
        printf("%lf^(1/2) = %lf\n", a, sqrt(a));
    }
    else
    {
        printf("Error! Squareroot of negative number is not allowed.\n");
    }
}

// Function to raise a base to the power of an exponent
void powerNumber(double base, double exponent)
{
    printf("%lf^%lf = %lf\n", base, exponent, pow(base, exponent));
}

void sineNumber(double a)
{
    printf("sin(%lf) = %lf\n", a, sin(a));
}

void cosineNumber(double a)
{
    printf("cos(%lf) = %lf\n", a, cos(a));
}

void tangentNumber(double a)
{
    printf("tan(%lf) = %lf\n", a, tan(a));
}

int main()
{
    printf("***************Calculator***************\n");

    char operator;  // Variable to store the chosen operator
    double n1, n2;  // Variables to store numbers entered by the user
    int status = 1; // Status to control the main loop

    // Loop until the user decides to quit by entering 'Q' or 'q'
    while (status)
    {

        // Display available operations
        printf("\nEnter an operator\n");
        printf("Press + to Add numbers\n");
        printf("Press - to Subtract numbers\n");
        printf("Press * to Multiply numbers\n");
        printf("Press / to Divide numbers\n");
        printf("Press S to Square number\n");
        printf("Press R to Squareroot number\n");
        printf("Press P to get Power of the number\n");
        printf("Press A to get Sine of the number\n");
        printf("Press C to get Cosine of the number\n");
        printf("Press T to get Tangent of the number\n");
        printf("Press Q to Quit\n");
        printf("Enter Operator: ");
        scanf(" %c", &operator); // Read the operator from user

        // Switch case to perform the chosen operation
        switch (operator)
        {
        case '+':
            printf("Enter numbers: ");
            scanf("%lf %lf", &n1, &n2);
            addNumbers(n1, n2);
            break;

        case '-':
            printf("Enter numbers: ");
            scanf("%lf %lf", &n1, &n2);
            subNumbers(n1, n2);
            break;

        case '*':
            printf("Enter numbers: ");
            scanf("%lf %lf", &n1, &n2);
            multiplyNumbers(n1, n2);
            break;

        case '/':
            printf("Enter numbers: ");
            scanf("%lf %lf", &n1, &n2);
            divideNumbers(n1, n2);
            break;

        case 'S':
        case 's':
            printf("Enter number: ");
            scanf("%lf", &n1);
            squareNumber(n1);
            break;

        case 'R':
        case 'r':
            printf("Enter number: ");
            scanf("%lf", &n1);
            sqrtNumber(n1);
            break;

        case 'P':
        case 'p':
            printf("Enter numbers: ");
            scanf("%lf %lf", &n1, &n2);
            powerNumber(n1, n2);
            break;

        case 'A':
        case 'a':
            printf("Enter number (in radians): ");
            scanf("%lf", &n1);
            sineNumber(n1);
            break;

        case 'C':
        case 'c':
            printf("Enter number (in radians): ");
            scanf("%lf", &n1);
            cosineNumber(n1);
            break;

        case 'T':
        case 't':
            printf("Enter number (in radians): ");
            scanf("%lf", &n1);
            tangentNumber(n1);
            break;
        case 'Q':
        case 'q':
            printf("Exiting Program ...\n");
            status = 0;
            break;

        default:
            printf("Error! Entered Operator is not correct according to the program. Please try again.\n");
            break;
        }
    }

    return 0;
}

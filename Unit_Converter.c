#include <stdio.h>

// Function prototypes
void temperatureConverter();
void currencyConverter();
void massConverter();

int main() {
    char category;
    printf("Welcome to the Enhanced Unit Converter!\n");
    printf("Select a conversion category:\n");
    printf("T - Temperature\nC - Currency\nM - Mass\n");
    printf("Please enter your choice: ");
    scanf(" %c", &category);

    switch(category) {
        case 'T':
        case 't':
            temperatureConverter();
            break;
        case 'C':
        case 'c':
            currencyConverter();
            break;
        case 'M':
        case 'm':
            massConverter();
            break;
        default:
            printf("Invalid category. Please restart and enter a valid choice.\n");
    }
    return 0;
}

void temperatureConverter() {
    int choice;
    float fahrenheit, celsius, kelvin;

    printf("Temperature Conversion Options:\n");
    printf("1 - Fahrenheit to Celsius\n");
    printf("2 - Celsius to Fahrenheit\n");
    printf("3 - Celsius to Kelvin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Fahrenheit temperature: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32) * 5.0 / 9.0;
        printf("Celsius: %.2f\n", celsius);
    } else if (choice == 2) {
        printf("Enter Celsius temperature: ");
        scanf("%f", &celsius);
        fahrenheit = (celsius * 9.0 / 5.0) + 32;
        printf("Fahrenheit: %.2f\n", fahrenheit);
    } else if (choice == 3) {
        printf("Enter Celsius temperature: ");
        scanf("%f", &celsius);
        kelvin = celsius + 273.15;
        printf("Kelvin: %.2f\n", kelvin);
    } else {
        printf("Invalid choice. Please restart.\n");
    }
}

void currencyConverter() {
    int choice;
    float usd, converted;

    printf("Currency Conversion Options:\n");
    printf("1 - USD to Euro\n");
    printf("2 - USD to JPY\n");
    printf("3 - USD to RMB\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter USD amount: ");
    scanf("%f", &usd);

    switch (choice) {
        case 1:
            converted = usd * 0.87;
            printf("Euro: %.2f\n", converted);
            break;
        case 2:
            converted = usd * 111.09;
            printf("JPY: %.2f\n", converted);
            break;
        case 3:
            converted = usd * 6.82;
            printf("RMB: %.2f\n", converted);
            break;
        default:
            printf("Invalid choice. Please restart.\n");
    }
}

void massConverter() {
    int choice;
    float inputMass, pounds;

    printf("Mass Conversion Options:\n");
    printf("1 - Ounces to Pounds\n");
    printf("2 - Grams to Pounds\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter mass in ounces: ");
        scanf("%f", &inputMass);
        pounds = inputMass * 0.0625;
        printf("Pounds: %.2f\n", pounds);
    } else if (choice == 2) {
        printf("Enter mass in grams: ");
        scanf("%f", &inputMass);
        pounds = inputMass * 0.00220462;
        printf("Pounds: %.2f\n", pounds);
    } else {
        printf("Invalid choice. Please restart.\n");
    }
}

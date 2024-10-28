#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRock() {

    printf("┈┈┈┈┈┈┈┈┳╮\n");
    printf("┈┈┈╭┻━━╮┃┃╮\n");
    printf("┈┈┈┃╲┏━╯┻┫\n");
    printf("┈┈┈╰╮╯┊┊┊╭╯\n");
}

void printPaper() {
    printf("┏━━━━━━━━━━━━┓\n");
    printf("┃            ┃\n");
    printf("┃            ┃\n");
    printf("┃            ┃\n");
    printf("┃            ┃\n");
    printf("┃            ┃\n");
    printf("┃            ┃\n");
    printf("┗━━━━━━━━━━━━┛\n");
}

void printScissors() {
    printf("┈┈┈┈╭╮╭╮\n");
    printf("┈┈┈┈┃┃┃┃\n");
    printf("┈┈┈┈┃┃┃┃\n");
    printf("┈┈┈┈┃┗┛┣┳╮\n");
    printf("┈┈┈╭┻━━╮┃┃╮\n");
    printf("┈┈┈┃╲┏━╯┻┫\n");
    printf("┈┈┈╰╮╯┊┊┊╭╯\n");
}

int main() {
    int playerChoice, computerChoice;
    const char *choices[] = {"Rock", "Paper", "Scissors"};
    char playAgain;

    // Seed the random number generator
    srand(time(NULL));

    do {
        printf("Choose:\n");
        printf("0: Rock\n");
        printf("1: Paper\n");
        printf("2: Scissors\n");
        printf("Enter your choice (0-2): ");
        scanf("%d", &playerChoice);

        if (playerChoice < 0 || playerChoice > 2) {
            printf("Invalid choice! Please enter 0, 1, or 2.\n");
            continue;
        }

        // Generate computer's choice
        computerChoice = rand() % 3;

        // Display player's choice
        printf("\nYou chose: %s\n", choices[playerChoice]);
        if (playerChoice == 0) printRock();
        else if (playerChoice == 1) printPaper();
        else if (playerChoice == 2) printScissors();

        // Display computer's choice
        printf("\nComputer chose: %s\n", choices[computerChoice]);
        if (computerChoice == 0) printRock();
        else if (computerChoice == 1) printPaper();
        else if (computerChoice == 2) printScissors();

        // Determine the winner
        if (playerChoice == computerChoice) {
            printf("\nIt's a tie!\n");
        } else if ((playerChoice == 0 && computerChoice == 2) ||
                   (playerChoice == 1 && computerChoice == 0) ||
                   (playerChoice == 2 && computerChoice == 1)) {
            printf("\nYou win!\n");
        } else {
            printf("\nYou lose!\n");
        }

        // Ask if the player wants to play again
        printf("\nDo you want to play again? (y for yes, q for quit): ");
        scanf(" %c", &playAgain);
        
        
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}

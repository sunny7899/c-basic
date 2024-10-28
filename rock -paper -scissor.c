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

void displayChoice(int choice) {
    if (choice == 0) printRock();
    else if (choice == 1) printPaper();
    else if (choice == 2) printScissors();
}

int getWinner(int playerChoice, int computerChoice) {
    if (playerChoice == computerChoice) return 0;  // Tie
    else if ((playerChoice == 0 && computerChoice == 2) ||
             (playerChoice == 1 && computerChoice == 0) ||
             (playerChoice == 2 && computerChoice == 1)) {
        return 1;  // Player wins
    }
    return -1; // Computer wins
}

int main() {
    int playerChoice, computerChoice;
    int wins = 0, losses = 0, ties = 0;
    const char *choices[] = {"Rock", "Paper", "Scissors"};
    char playAgain;

    srand(time(NULL));

    do {
        printf("\nChoose:\n");
        printf("0: Rock\n");
        printf("1: Paper\n");
        printf("2: Scissors\n");
        printf("Enter your choice (0-2): ");

        if (scanf("%d", &playerChoice) != 1 || playerChoice < 0 || playerChoice > 2) {
            printf("Invalid input! Please enter a number between 0 and 2.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        computerChoice = rand() % 3;

        printf("\nYou chose: %s\n", choices[playerChoice]);
        displayChoice(playerChoice);

        printf("\nComputer chose: %s\n", choices[computerChoice]);
        displayChoice(computerChoice);

        int result = getWinner(playerChoice, computerChoice);
        if (result == 0) {
            printf("\nIt's a tie!\n");
            ties++;
        } else if (result == 1) {
            printf("\nYou win!\n");
            wins++;
        } else {
            printf("\nYou lose!\n");
            losses++;
        }

        printf("\nPlay again? (y for yes, q for quit): ");
        scanf(" %c", &playAgain);
        while (getchar() != '\n');  // Clear the input buffer

    } while (playAgain == 'y' || playAgain == 'Y');

    printf("\nGame Summary:\n");
    printf("Wins: %d\n", wins);
    printf("Losses: %d\n", losses);
    printf("Ties: %d\n", ties);
    printf("Thanks for playing!\n");

    return 0;
}

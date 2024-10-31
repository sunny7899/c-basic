#include <stdio.h>

/*
 * This program is a simple number guessing game where the user tries to guess a number 
 * between 0 and 9. The program checks if the guessed number matches the corresponding 
 * value in a predefined array. After each round, the user is asked if they want to play again.
 */

int main() {
    int nums[] = {0, 9, 7, 3, 4, 8, 1, 2, 0, 6};
    int input_selected;
    char play_again;

    do {
        char msg[] = "This is simple!\nTry to guess a number between 0 and 9.\n";
        printf("%s", msg);
        printf("Enter your guess: ");
        scanf("%d", &input_selected);

        if (input_selected >= 0 && input_selected < 10) {
            if (input_selected == nums[input_selected]) {
                printf("You Won!\n");
            } else {
                printf("You Lost!\n");
            }
        } else {
            printf("Please enter a number between 0 and 9.\n");

#include <stdio.h>
#include <ctype.h>

// Function to display the Tic-Tac-Toe board
void displayBoard(char _1, char _2, char _3, char _4, char _5, char _6, char _7, char _8, char _9) {
    printf("\n %c | %c | %c \n------------\n", _1, _2, _3);
    printf(" %c | %c | %c \n------------\n", _4, _5, _6);
    printf(" %c | %c | %c \n\n", _7, _8, _9);
}

// Function to check if a player has won
int checkWin(char a, char b, char c, char playerSymbol) {
    return (a == playerSymbol && b == playerSymbol && c == playerSymbol);
}

// Function to clear invalid input from the buffer
void clearInputBuffer() {
    while (getchar() != '\n'); // Discards invalid input until a newline is found
}

int main() {
    char replay;

    do {
        int i, n;
        // Initialize the board cells as empty
        char _1 = ' ', _2 = ' ', _3 = ' ', _4 = ' ', _5 = ' ', _6 = ' ', _7 = ' ', _8 = ' ', _9 = ' ';
        char name_1[20], name_2[20];
        
        // Get player names
        printf("Player 1, enter your name: ");
        fgets(name_1, sizeof(name_1), stdin);
        printf("Player 2, enter your name: ");
        fgets(name_2, sizeof(name_2), stdin);

        // Assign symbols to players and display the initial board
        printf("\n 'X' is for %s '0' is for %s", name_1, name_2);
        displayBoard(_1, _2, _3, _4, _5, _6, _7, _8, _9);

        // Loop for each turn (maximum of 9 turns)
        for (i = 1; i <= 9; i++) {
            char playerSymbol = (i % 2 != 0) ? 'X' : '0'; // Alternate symbols between 'X' and '0'
            char* currentPlayer = (i % 2 != 0) ? name_1 : name_2;

            while (1) { // Loop to ensure valid position is chosen
                printf("%s, enter your position (1-9): ", currentPlayer);
                if (scanf("%d", &n) != 1) { // Check if input is valid
                    printf("Invalid input. Please enter a number between 1 and 9.\n");
                    clearInputBuffer(); // Clear the invalid input from the buffer
                    continue;
                }
                
                if (n < 1 || n > 9) { // Check for valid range
                    printf("Invalid position. Please try again.\n");
                    continue;
                }

                // Determine the selected board cell based on position
                char *position = NULL;
                switch (n) {
                    case 1: position = &_1; break;
                    case 2: position = &_2; break;
                    case 3: position = &_3; break;
                    case 4: position = &_4; break;
                    case 5: position = &_5; break;
                    case 6: position = &_6; break;
                    case 7: position = &_7; break;
                    case 8: position = &_8; break;
                    case 9: position = &_9; break;
                }
                
                // Place symbol if position is empty, otherwise prompt again
                if (*position == ' ') {
                    *position = playerSymbol;
                    break;
                } else {
                    printf("Position already taken. Try again.\n");
                }
            }

            // Display updated board after each move
            displayBoard(_1, _2, _3, _4, _5, _6, _7, _8, _9);

            // Check for win conditions
            if (checkWin(_1, _2, _3, playerSymbol) || checkWin(_4, _5, _6, playerSymbol) || 
                checkWin(_7, _8, _9, playerSymbol) || checkWin(_1, _4, _7, playerSymbol) || 
                checkWin(_2, _5, _8, playerSymbol) || checkWin(_3, _6, _9, playerSymbol) || 
                checkWin(_1, _5, _9, playerSymbol) || checkWin(_3, _5, _7, playerSymbol)) {
                printf("%s wins!\n", currentPlayer);
               break;
            }
        }

        if (i > 9) {
            // If all positions are filled with no winner, it's a draw
            printf("It's a draw!\n");
        }

        // Ask players if they want to play again
        printf("Do you want to play again? (y/n): ");
        clearInputBuffer(); // Clear the buffer before taking the next input
        scanf("%c", &replay);

    } while (tolower(replay) == 'y'); // Repeat if players choose 'y' or 'Y'

    printf("Thanks for playing!\n");
    return 0;
}

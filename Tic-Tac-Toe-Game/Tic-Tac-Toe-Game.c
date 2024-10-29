#include <stdio.h>
#include <ctype.h>
#include <time.h>

int player1Wins = 0, player2Wins = 0, draws = 0;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[]) {
    printf("\n %c | %c | %c \n------------\n", board[0], board[1], board[2]);
    printf(" %c | %c | %c \n------------\n", board[3], board[4], board[5]);
    printf(" %c | %c | %c \n\n", board[6], board[7], board[8]);
}

// Function to check if a player has won
int checkWin(char board[], char playerSymbol) {
    return (
        (board[0] == playerSymbol && board[1] == playerSymbol && board[2] == playerSymbol) ||
        (board[3] == playerSymbol && board[4] == playerSymbol && board[5] == playerSymbol) ||
        (board[6] == playerSymbol && board[7] == playerSymbol && board[8] == playerSymbol) ||
        (board[0] == playerSymbol && board[3] == playerSymbol && board[6] == playerSymbol) ||
        (board[1] == playerSymbol && board[4] == playerSymbol && board[7] == playerSymbol) ||
        (board[2] == playerSymbol && board[5] == playerSymbol && board[8] == playerSymbol) ||
        (board[0] == playerSymbol && board[4] == playerSymbol && board[8] == playerSymbol) ||
        (board[2] == playerSymbol && board[4] == playerSymbol && board[6] == playerSymbol)
    );
}

// Function to clear invalid input from the buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Function to display the main menu
void showMenu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Start New Game\n");
    printf("2. View Scoreboard\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

// Function to display the scoreboard
void displayScoreboard(char* name1, char* name2) {
    printf("\n--- Scoreboard ---\n");
    printf("%s Wins: %d\n%s Wins: %d\nDraws: %d\n", name1, player1Wins, name2, player2Wins, draws);
}

// Function to handle the AI move
void aiMove(char board[], char aiSymbol) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = aiSymbol;  // AI places its symbol
            break;
        }
    }
}

// Function to handle undo last move
void undoLastMove(char board[], int moves[], int* moveCount) {
    if (*moveCount > 0) {
        int lastMove = moves[--(*moveCount)];
        board[lastMove] = ' ';  // Reset the last position
    } else {
        printf("No moves to undo!\n");
    }
}

// Function to prompt for a timed move
int timedMove(char* currentPlayer) {
    time_t start, end;
    int position;

    printf("%s, you have 10 seconds to make a move (1-9): ", currentPlayer);
    time(&start);

    if (scanf("%d", &position) != 1) {
        time(&end);
        if (difftime(end, start) > 10.0) {
            printf("Time's up! Skipping your turn.\n");
            return -1;  // Time expired, move skipped
        }
    }
    return position;
}

int main() {
    char replay;
    char board[9];
    int moves[9];
    int moveCount = 0;
    char name1[20], name2[20];

    printf("Enter Player 1 name: ");
    fgets(name1, sizeof(name1), stdin);
    printf("Enter Player 2 name: ");
    fgets(name2, sizeof(name2), stdin);

    while (1) {
        int choice;
        showMenu();
        scanf("%d", &choice);
        clearInputBuffer();

        if (choice == 3) {
            printf("Exiting the game. Thanks for playing!\n");
            break;
        } else if (choice == 2) {
            displayScoreboard(name1, name2);
            continue;
        } else if (choice != 1) {
            printf("Invalid option. Please try again.\n");
            continue;
        }

        // Initialize the board cells and move count
        for (int i = 0; i < 9; i++) board[i] = ' ';
        moveCount = 0;
        displayBoard(board);

        // Main game loop
        for (int i = 1; i <= 9; i++) {
            char playerSymbol = (i % 2 != 0) ? 'X' : '0';
            char* currentPlayer = (i % 2 != 0) ? name1 : name2;

            int n;
            if (strcmp(currentPlayer, "AI") == 0) {
                aiMove(board, playerSymbol);
            } else {
                while (1) {
                    n = timedMove(currentPlayer);
                    if (n == -1) break;

                    if (n < 1 || n > 9 || board[n - 1] != ' ') {
                        printf("Invalid or taken position. Try again.\n");
                        continue;
                    }
                    board[n - 1] = playerSymbol;
                    moves[moveCount++] = n - 1;
                    break;
                }
            }
            displayBoard(board);

            if (checkWin(board, playerSymbol)) {
                printf("%s wins!\n", currentPlayer);
                if (playerSymbol == 'X') player1Wins++;
                else player2Wins++;
                break;
            }
        }

        // Update scoreboard if it’s a draw
        if (moveCount >= 9) {
            printf("It's a draw!\n");
            draws++;
        }

        // Ask if players want to play again
        printf("Do you want to play again? (y/n): ");
        clearInputBuffer();
        scanf("%c", &replay);
        if (tolower(replay) != 'y') break;
    }

    return 0;
}

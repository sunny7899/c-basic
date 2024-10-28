#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MINES 10

char board[HEIGHT][WIDTH]; // The visible board
char mines[HEIGHT][WIDTH]; // The actual board with mines
int revealed[HEIGHT][WIDTH]; // To keep track of revealed cells

void setup() {
    // Initialize the boards
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = '*'; // Hidden cell
            mines[i][j] = '0'; // No mine initially
            revealed[i][j] = 0; // All cells are hidden
        }
    }

    // Place mines randomly
    srand(time(NULL));
    for (int i = 0; i < MINES; i++) {
        int x, y;
        do {
            x = rand() % HEIGHT;
            y = rand() % WIDTH;
        } while (mines[x][y] == '*'); // Ensure no duplicate mines
        mines[x][y] = '*';

        // Increment numbers around the mine
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (x + dx >= 0 && x + dx < HEIGHT && y + dy >= 0 && y + dy < WIDTH && mines[x + dx][y + dy] != '*') {
                    mines[x + dx][y + dy]++;
                }
            }
        }
    }
}

void draw() {
    printf("Minesweeper\n");
    printf("  ");
    for (int i = 0; i < WIDTH; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("%d ", i);
        for (int j = 0; j < WIDTH; j++) {
            if (revealed[i][j]) {
                printf("%c ", mines[i][j]);
            } else {
                printf("%c ", board[i][j]);
            }
        }
        printf("\n");
    }
}

void reveal(int x, int y) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH || revealed[x][y])
        return;

    revealed[x][y] = 1; // Reveal the cell

    if (mines[x][y] == '0') {
        // If no adjacent mines, reveal surrounding cells
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                reveal(x + dx, y + dy);
            }
        }
    }
}

int checkWin() {
    int coveredCells = 0;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (!revealed[i][j]) {
                coveredCells++;
            }
        }
    }
    return coveredCells == MINES; // Win if the number of covered cells equals the number of mines
}

int main() {
    setup();
    int gameOver = 0;

    while (!gameOver) {
        draw();
        printf("Enter row and column to reveal (or -1 -1 to exit): ");
        int x, y;
        scanf("%d %d", &x, &y);

        if (x == -1 && y == -1) {
            printf("Exiting the game.\n");
            break;
        }

        if (mines[x][y] == '*') {
            printf("Game Over! You hit a mine.\n");
            gameOver = 1;
        } else {
            reveal(x, y);
        }

        if (checkWin()) {
            printf("Congratulations! You've cleared the minefield!\n");
            gameOver = 1;
        }
    }

    // Reveal the entire board at the end
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            revealed[i][j] = 1; // Reveal all cells
        }
    }
    draw(); // Show final board

    return 0;
}

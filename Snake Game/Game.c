#include <stdio.h>
#include <conio.h>  // For getch() and kbhit() (Windows)
#include <stdlib.h>
#include <unistd.h> // For sleep() (Linux)
#include <stdbool.h>

#define WIDTH 20
#define HEIGHT 10

int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
char dir;

void setup() {
    dir = ' '; // Initial direction
    x = WIDTH / 2; // Start position
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH; // Random fruit position
    fruitY = rand() % HEIGHT;
    score = 0; // Initialize score
    nTail = 0; // Initialize tail length
}

void draw() {
    system("cls"); // Clear console (Windows)
    // system("clear"); // Uncomment for Linux

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#"); // Wall on the left
            if (i == y && j == x)
                printf("O"); // Snake head
            else if (i == fruitY && j == fruitX)
                printf("F"); // Fruit
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Snake tail
                        print = true;
                    }
                }
                if (!print)
                    printf(" ");
            }
            if (j == WIDTH - 1)
                printf("#"); // Wall on the right
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");
    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) { // Check if a key is pressed (Windows)
        switch (_getch()) {
            case 'a':
                dir = 'L'; // Move left
                break;
            case 'd':
                dir = 'R'; // Move right
                break;
            case 'w':
                dir = 'U'; // Move up
                break;
            case 's':
                dir = 'D'; // Move down
                break;
            case 'x':
                exit(0); // Exit
                break;
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x; // Update tail position
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case 'L':
            x--;
            break;
        case 'R':
            x++;
            break;
        case 'U':
            y--;
            break;
        case 'D':
            y++;
            break;
    }

    // Fruit collision
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++; // Increase tail length
    }

    // Boundary collision
    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    // Self collision
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y) {
            exit(0); // Exit on collision
        }
    }
}

int main() {
    setup();
    while (true) {
        draw();
        input();
        logic();
        usleep(100000); // Sleep for 100 ms (Linux)
        // Sleep(100); // Uncomment for Windows
    }
    return 0;
}

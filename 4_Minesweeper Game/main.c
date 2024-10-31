#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MINES 10

char board[SIZE][SIZE];
char revealed[SIZE][SIZE];
int minesPlaced = 0;

void initializeBoard() {
    int i;
    for (i = 0; i < SIZE; i++) {
        int j;
        for (j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
            revealed[i][j] = 0;
        }
    }
}

void printBoard() {
    printf("  ");
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);
    }
    printf("\n");

    for (i = 0; i < SIZE; i++) {
        printf("%2d", i);
        int j;
        for (j = 0; j < SIZE; j++) {
            if (revealed[i][j] == 0) {
                printf(" .");
            } else if (board[i][j] == '*') {
                printf(" *");
            } else {
                int count = 0;
                if (i > 0 && j > 0 && board[i - 1][j - 1] == '*') count++;
                if (i > 0 && board[i - 1][j] == '*') count++;
                if (i > 0 && j < SIZE - 1 && board[i - 1][j + 1] == '*') count++;
                if (j > 0 && board[i][j - 1] == '*') count++;
                if (j < SIZE - 1 && board[i][j + 1] == '*') count++;
                if (i < SIZE - 1 && j > 0 && board[i + 1][j - 1] == '*') count++;
                if (i < SIZE - 1 && board[i + 1][j] == '*') count++;
                if (i < SIZE - 1 && j < SIZE - 1 && board[i + 1][j + 1] == '*') count++;
                printf(" %d", count);
            }
        }
        printf("\n");
    }
}

void placeMines() {
    while (minesPlaced < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        if (board[x][y] != '*') {
            board[x][y] = '*';
            minesPlaced++;
        }
    }
}

int countAdjacentMines(int x, int y) {
    int count = 0;
    if (x > 0 && y > 0 && board[x - 1][y - 1] == '*') count++;
    if (x > 0 && board[x - 1][y] == '*') count++;
    if (x > 0 && y < SIZE - 1 && board[x - 1][y + 1] == '*') count++;
    if (y > 0 && board[x][y - 1] == '*') count++;
    if (y < SIZE - 1 && board[x][y + 1] == '*') count++;
    if (x < SIZE - 1 && y > 0 && board[x + 1][y - 1] == '*') count++;
    if (x < SIZE - 1 && board[x + 1][y] == '*') count++;
    if (x < SIZE - 1 && y < SIZE - 1 && board[x + 1][y + 1] == '*') count++;
    return count;
}

void reveal(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE || revealed[x][y] == 1)
        return;

    revealed[x][y] = 1;

    if (board[x][y] == ' ' && countAdjacentMines(x, y) == 0) {
        reveal(x - 1, y - 1);
        reveal(x - 1, y);
        reveal(x - 1, y + 1);
        reveal(x, y - 1);
        reveal(x, y + 1);
        reveal(x + 1, y - 1);
        reveal(x + 1, y);
        reveal(x + 1, y + 1);
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();
    placeMines();
    int x, y;

    printf("Minesweeper!\n");
    printf("Enter coordinates (x y).\n");

    while (1) {
        printBoard();
        printf("\nEnter coordinates (x y): ");
        scanf("%d %d", &x, &y);

        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        if (board[x][y] == '*') {
            printf("Game Over! You hit a mine!\n");
            break;
        }

        reveal(x, y);
        int uncoveredTiles = SIZE * SIZE - minesPlaced;
        if (uncoveredTiles == 0) {
            printf("You won the game!\n");
            break;
        }
    }

    return 0;
}

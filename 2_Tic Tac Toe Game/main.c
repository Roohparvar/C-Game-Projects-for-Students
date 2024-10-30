#include <stdio.h>

char board[3][3];
int currentPlayer = 1;
int totalMoves = 0;

void initializeBoard() {
    int i;
    for (i = 0; i < 3; i++) {
        int j;
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int isMoveValid(int row, int col) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        return 1;
    }
    return 0;
}

int isGameOver() {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    if (totalMoves == 9)
        return -1;

    return 0;
}

void makeMove(int row, int col) {
    if (isMoveValid(row, col)) {
        if (currentPlayer == 1) {
            board[row][col] = 'X';
            currentPlayer = 2;
        } else {
            board[row][col] = 'O';
            currentPlayer = 1;
        }
        totalMoves++;
    } else {
        printf("Invalid move. Try again.\n");
    }
}

int main() {
    initializeBoard();
    int row, col;
    int gameState = 0;

    while (gameState == 0) {
        displayBoard();
        printf("input a row number, choosing from 0, 1, or 2, and then press 'Enter.' \nNext, input a column number, selecting from 0, 1, or 2, and press 'Enter' again\n");
        printf("Player %d's turn:\n", currentPlayer);
        scanf("%d %d", &row, &col);
        makeMove(row, col);
        gameState = isGameOver();
    }

    displayBoard();
    if (gameState == -1) {
        printf("It's a draw!\n");
    } else {
        printf("Player %d wins!\n", gameState);
    }

    return 0;
}

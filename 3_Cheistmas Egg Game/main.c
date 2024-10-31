#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 5
#define NUM_EGGS 5

char grid[GRID_SIZE][GRID_SIZE];
int eggsFound = 0,r=1;

void initializeGrid() {
    int i;
    for (i = 0; i < GRID_SIZE; i++) {
        int j;
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = '.';
        }
    }
}

void placeEggs() {
    srand(time(NULL));
    int i;
    for (i = 0; i < NUM_EGGS; i++) {
        int x, y;
        do {
            x = rand() % GRID_SIZE;
            y = rand() % GRID_SIZE;
        } while (grid[x][y] != '.');
        grid[x][y] = 'E';
    }
}

void printGrid() {
    int i;
    for (i = 0; i < GRID_SIZE; i++) {
        int j;
        for (j = 0; j < GRID_SIZE; j++) {
                if(grid[i][j]=='E'){
                    printf(". ");
                }else{
                    printf("%c ", grid[i][j]);
                }

        }
        printf("\n");
    }
}

bool playGame() {
    int x, y;
    printf("\n********************Find the Christmas Eggs (Round %d) ********************\nEnter row and column (e.g., 1 2):\n", r);
    scanf("%d %d", &x, &y);
    r=r+1;
    if (x < 1 || x > GRID_SIZE || y < 1 || y > GRID_SIZE) {
        printf("Invalid input. Try again.\n");
        return false;
    }

    x--;
    y--;

    if (grid[x][y] == 'E') {
        printf("You found a Christmas Egg!\n");
        grid[x][y] = 'X';
        eggsFound++;
    } else {
        printf("No Christmas Egg here. Keep searching!\n");
    }

    return true;
}

int main() {
    initializeGrid();
    placeEggs();

    while (eggsFound < NUM_EGGS) {
        printGrid();
        if (!playGame()) {
            continue;
        }
    }

    printf("\n************************************************************************\nCongratulations! You found all the Christmas Eggs!\n");

    return 0;
}

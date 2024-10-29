#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberToGuess, guess, attempts = 0;
    srand(time(0));
    numberToGuess = rand() % 100 + 1;

    printf("I've selected a random number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < numberToGuess) {
            printf("Try a higher number.\n");
        } else if (guess > numberToGuess) {
            printf("Try a lower number.\n");
        } else {
            printf("Congratulations! You've guessed the number in %d attempts!\n", attempts);
        }
    } while (guess != numberToGuess);

    return 0;
}

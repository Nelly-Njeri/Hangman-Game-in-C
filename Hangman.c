#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Array of words for the game
char *words[] = {"hangman", "computer", "programming", "language", "software"};

int main() {
    srand(time(NULL)); // Seed for generating random numbers
    int n = sizeof(words) / sizeof(words[0]); // Number of words in the array
    char *word = words[rand() % n]; // Randomly select a word from the array
    int len = strlen(word); // Length of the word
    char guess[len]; // Array to store the guessed characters
    int attempts = 0;
    int maxAttempts = 6; // Maximum number of attempts allowed

    // Initialize the guess array with underscores
    for (int i = 0; i < len; i++) {
        guess[i] = '_';
    }

    printf("Welcome to Hangman!\n");
    printf("Guess the word: ");
    for (int i = 0; i < len; i++) {
        printf("%c ", guess[i]);
    }
    printf("\n");

    while (attempts < maxAttempts) {
        char letter;
        printf("Enter a letter: ");
        scanf(" %c", &letter);

        int correct = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] == letter) {
                guess[i] = letter;
                correct = 1;
            }
        }

        if (!correct) {
            attempts++;
            printf("Incorrect guess, %d attempts remaining.\n", maxAttempts - attempts);
        } else {
            printf("Correct guess!\n");
        }

        // Display the current state of the word
        for (int i = 0; i < len; i++) {
            printf("%c ", guess[i]);
        }
        printf("\n");

        // Check if the word has been guessed
        if (strcmp(word, guess) == 0) {
            printf("Congratulations, you guessed the word!\n");
            break;
        }
    }

    if (attempts == maxAttempts) {
        printf("You ran out of attempts. The word was: %s\n", word);
    }

    return 0;
}

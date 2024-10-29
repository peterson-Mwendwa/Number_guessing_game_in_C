#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_game(int range);
void display_welcome();
int get_difficulty_level();
int play_again();

int main() {
    display_welcome();
    int difficulty = get_difficulty_level();
    int range;

    // Set the range based on difficulty
    if (difficulty == 1) {
        range = 10;  // Easy: 1 to 10
    } else if (difficulty == 2) {
        range = 50;  // Medium: 1 to 50
    } else {
        range = 100; // Hard: 1 to 100
    }

    srand(time(NULL)); // Seed the random number generator once

    do {
        play_game(range);
    } while (play_again()); // Ask user if they want to play again

    return 0;
}

// Function to display a welcome message
void display_welcome() {
    printf("Welcome to the Number Guessing Game!\n");
    printf("My name is Valilian Peterson Mwendwa!\n");
    printf("You will try to guess a randomly generated number.\n");
    printf("All the best hope you'll enjoy!\n");
}

// Function to get the difficulty level from the user
int get_difficulty_level() {
    int level;
    printf("Choose a difficulty level:\n");
    printf("1. Easy (1-10)\n");
    printf("2. Medium (1-50)\n");
    printf("3. Hard (1-100)\n");
    printf("Enter your choice (1-3): ");
    
    while (1) {
        scanf("%d", &level);
        if (level >= 1 && level <= 3) {
            break; // Valid input
        } else {
            printf("Invalid choice. Please enter 1, 2, or 3: ");
        }
    }

    return level;
}

// Function to play the guessing game
void play_game(int range) {
    int number_to_guess, user_guess, attempts = 0, score;
    
    number_to_guess = rand() % range + 1; // Random number between 1 and 'range'

    printf("\nI have generated a number between 1 and %d. Try to guess it!\n", range);

    while (1) {
        printf("Enter your guess: ");
        scanf("%d", &user_guess);
        attempts++;

        if (user_guess < 1 || user_guess > range) {
            printf("Please guess a number within the range (1 to %d).\n", range);
            continue;
        }

        if (user_guess < number_to_guess) {
            if (number_to_guess - user_guess <= 5) {
                printf("Too low! You're very close!\n");
            } else {
                printf("Too low! Try again.\n");
            }
        } else if (user_guess > number_to_guess) {
            if (user_guess - number_to_guess <= 5) {
                printf("Too high! You're very close!\n");
            } else {
                printf("Too high! Try again.\n");
            }
        } else {
            // Calculate score based on attempts
            score = (range / attempts) * 100; // Score based on attempts taken
            printf("Congratulations! You've guessed the number %d in %d attempts!\n", number_to_guess, attempts);
            printf("Your score: %d\n", score < 0 ? 0 : score); // Ensure score is not negative
            break;
        }
    }
}

// Function to ask the user if they want to play again
int play_again() {
    char response;
    printf("Do you want to play again? (y/n): ");
    while (1) {
        scanf(" %c", &response); // Leading space ignores whitespace characters
        if (response == 'y' || response == 'Y') {
            return 1; // User wants to play again
        } else if (response == 'n' || response == 'N') {
            printf("Thanks for playing! Goodbye!\n");
            return 0; // Exit the game
        } else {
            printf("Invalid input. Please enter 'y' or 'n': ");
        }
    }
}

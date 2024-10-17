#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int generate_random_number();
int get_player_guess();
void check_guess(int player_guess, int random_number);
void play_game();

int main() {
    srand(time(0));  // Seed the random number generator
    play_game();     // Start the game
    return 0;
}

void play_game() {
    char play_again;
    do {
        int random_number = generate_random_number();
        int player_guess = 0;
        int attempts = 0;

        printf("Guess the number (between 1 and 100):\n");
        while (player_guess != random_number) {
            player_guess = get_player_guess();
            attempts++;
            check_guess(player_guess, random_number);
        }

        printf("Congratulations! You've guessed the number in %d attempts.\n", attempts);
        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &play_again);
    } while (play_again == 'y' || play_again == 'Y');
}

int generate_random_number() {
    return rand() % 100 + 1;  // Generate number between 1 and 100
}

int get_player_guess() {
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    return guess;
}

void check_guess(int player_guess, int random_number) {
    if (player_guess < random_number) {
        printf("Too low! Try again.\n");
    } else if (player_guess > random_number) {
        printf("Too high! Try again.\n");
    }
}

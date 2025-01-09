#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    // Print the guessing game head
    printf("********************************\n");
    printf("* Welcome to The Guessing Game *\n");
    printf("********************************\n");

    // Store the secret number in a variable and making it random
    
    int seconds = time(0);
    srand(seconds);

    int bigNumber = rand();

    int secretNumber = bigNumber % 100;

    int attempts = 1;

    int playerGuess;

    int playerWin = 0;

    double score = 1000;

    int hit = 0;

    // Adding difficulty into the game
    int level;
    printf("Choose the game level\n");
    printf("(1)Easy (2)Medium (3)Hard\n\n");
    printf("Choice: ");
    scanf("%d", &level);

    int playerAttempts;

    switch (level) {
    case 1:
        playerAttempts = 20;
        break;
    case 2:
        playerAttempts = 15;
        break;
    default:
        playerAttempts = 6;
        break;
    }
    
    // Building the game menu
    for (int i = 1; i <= playerAttempts; i++){

        printf("Attempt %d\n", attempts);
        printf("What is your guess? ");
        scanf("%d", &playerGuess);

        if(playerGuess < 0){
            printf("Your guess cannot be a negative number!\n");
            continue;
        }

        // Building the code's conditionals

        hit = (playerGuess == secretNumber);

        int greater = playerGuess > secretNumber;

        if(hit){
            break;
        }

        else if (greater){
            printf("Your guess was greater than the secret number.\n");
        } 

        else {
            printf("Your guess was less than the secret number.\n");
        }
        
        attempts++;

        double lostScore = abs(playerGuess - secretNumber) / (double) 2;
        score -= lostScore; 

    }

    printf("\nEnd game\n");

    if (hit){
        printf("Congrats! You've got it right.\n");
        printf("You finished the game after %d attempts\n", playerAttempts-1);
        printf("Total score: %.1f\n", score);
    } else {
        printf("Game Over! Try again\n");
    }
    
    return 0;

}
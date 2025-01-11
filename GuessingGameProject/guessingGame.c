#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    // Print the guessing game head
printf("\n\n");
printf("      __  __   _   _   ___ ___      \n"); 
printf("     / _` | | | |/ _ \\/ __/ __|     \n");
printf("    | (_| | |_| |  __/\\__ \\__ \\     \n");
printf("     \\__, |\\__,_|\\___||___/___/     \n");
printf("      __/ |                         \n");
printf("     |___/                          \n");
printf("\n\n");

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

        printf("\n\nAttempt %d\n", attempts);
        printf("What is your guess? ");
        scanf("%d", &playerGuess);

        if(playerGuess < 0){
            printf("\nYour guess cannot be a negative number!\n");
            continue;
        }

        // Building the code's conditionals

        hit = (playerGuess == secretNumber);

        int greater = playerGuess > secretNumber;

        if(hit){
            break;
        }
        else if (greater){
            printf("\nYour guess was greater than the secret number.\n");
        } 
        else {
            printf("\nYour guess was less than the secret number.\n");
        }
        
        attempts++;

        double lostScore = abs(playerGuess - secretNumber) / (double) 2;
        score -= lostScore; 

    }

    if (hit){
        printf("Congrats! You've got it right.\n");
        printf("You finished the game after %d attempts\n", attempts);
        printf("Total score: %.1f\n\n", score);
    } else {
        printf("\n\n");
        printf("       ___                         ___                     \n");  
        printf("     / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __     \n");
        printf("    | |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|    \n");
        printf("    | |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |       \n");
        printf("     \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|       \n");
        printf("\n\n");

    }
    
    return 0;

}
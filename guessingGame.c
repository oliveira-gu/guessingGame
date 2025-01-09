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

    int playerAttempts = 1;

    int playerGuess;

    int playerWin = 0;

    double score = 1000;

    // Building the game menu
    while (playerWin == 0){

        printf("Attempt %d\n", playerAttempts);
        printf("What is your guess? ");
        scanf("%d", &playerGuess);

        if(playerGuess < 0){
            printf("Your guess cannot be a negative number!\n");
            continue;
        }

        // Building the code's conditionals
        int hit = (playerGuess == secretNumber);
        int greater = playerGuess > secretNumber;

        if(hit){
            printf("Congrats! You've got it right.\n");
            playerWin = 1;
        }

        else if (greater){
            printf("Your guess was greater than the secret number.\n");
        } 

        else {
            printf("Your guess was less than the secret number.\n");
        }
        
        playerAttempts++;

        double lostScore = abs(playerGuess - secretNumber) / (double) 2;
        score -= lostScore; 

    }
    
    printf("\nEnd game\n");
    printf("You finished the game after %d attempts\n", playerAttempts-1);
    printf("Total score: %.1f\n", score);
    return 0;

}
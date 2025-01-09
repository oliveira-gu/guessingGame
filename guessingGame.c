#include <stdio.h>


int main(){
    
    // Print the guessing game head
    printf("********************************\n");
    printf("* Welcome to The Guessing Game *\n");
    printf("********************************\n");

    // Store the secret number in a variable
    int secretNumber = 10;
    int playerAttempts = 1;
    int playerGuess;
    int playerWin = 0;

    // Building the game menu
    while (playerWin == 0){

        printf("Attempt %d\n", playerAttempts);
        printf("What is your guess? ");
        scanf("%d", &playerGuess);

        if(playerGuess < 0){
            printf("Your guess cannot be a negative number!\n");
            continue;
        }

        // printf("Oh, so %d is your guess? ", playerGuess);

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
    }
    
    printf("\nEnd game\n");
    printf("You finished the game after %d attempts\n", playerAttempts-1);
    return 0;

}
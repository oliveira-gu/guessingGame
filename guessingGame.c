#include <stdio.h>

int main(){
    
    // Print the guessing game head
    printf("********************************\n");
    printf("* Welcome to The Guessing Game *\n");
    printf("********************************\n");

    // Store the secret number in a variable
    int secretNumber;
    
    printf("What is your guess? ");
    scanf("%d", &secretNumber);
    printf("Oh, so %d is your guess? ", secretNumber);

    return 0;
}
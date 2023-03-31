//number guessing game

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    char diff[15];
    int difficulty;
    printf("Choose your difficulty : Easy, Mid or Hard \n");
    scanf("%s", diff);
    if(strcmp("Easy", diff) == 0){
        difficulty = 20;
    }
    if(strcmp("Mid", diff)==0){
        difficulty = 50;
    }
    if(strcmp("Hard", diff) == 0){
        difficulty = 100;
    }

    srand(time(NULL));
    int n = rand()%difficulty;
    

    int g;
    int score = 0;
    while(1){
        printf("Make your guess! \n");
        scanf("%d", &g);
        score++;
        if(g < n){
            printf("Too low! \n");
        }

        else if(g > n){
            printf("Too high! \n");
        }
        else {
            printf("You guessed the right word in %d tries!", score);
            break;
        }
        
    }
    


    return 0;
}
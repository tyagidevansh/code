#include <stdio.h>
#include <ctype.h>

int main(){

    char questions[][100] = {"1. What year did the C language debut? \n",
                             "2. Who is credited with creading C? \n",
                             "3. What is the predecessor of C? \n"};

    char options[][100] = {"A. 1969", "B. 1962", "C. 1975", "D. 1999",
                            "A. Dennis Ritchie", "B. Nikola Tesla", "C. John Carman", "D. Yur mom",
                            "A. C++", "B. B", "C. C#", "D. Python"};
    
    char answers[3] = {'A', 'A', 'A'};

    int numberofQuestions = sizeof(questions)/sizeof(questions[0]);

    char guess;
    int score = 0;

    printf("QUIZ GAME\n");

    for(int i = 0; i < numberofQuestions; i++){
        printf("*********************************\n");
        printf("%s", questions[i]);

        for(int j = (i*4); j<(i*4) + 4; j++){
            printf("%s \n", options[j]);
        }

        printf("guess: ");
        scanf("%c", &guess);
        scanf("%c"); //clears \n from input buffer

        guess = toupper(guess);
        

        if(guess == answers[i]){
            printf("CORRECT! \n");
            score++;
        }
        else{
            printf("WRONG! \n");
        }
    }
    printf("FINAL SCORE: %d/%d", score, numberofQuestions);


    return 0;
}
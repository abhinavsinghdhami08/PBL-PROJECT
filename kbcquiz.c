#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure
struct Question {
    char question[100];
    char options[4][50];
    char answer;
};

int main() {

    // Array of structures (Questions)
    struct Question q[5] = {
        {"What is the correct extension of a c program?",
         {"A. .cpp", "B. .java", "C. .c", "D. .py"},
         'C'},

        {"Which function is used to print the output in C?",
         {"A. print()", "B. printf()", "C. cout", "D. display()"},
         'B'},

        {"Which header file is required for printf()?",
         {"A. conio.h", "B. stdio.h", "C. math.h", "D. string.h"},
         'B'},

        {"Which language is used for system programming?",
         {"A. Python", "B. C", "C. Java", "D. HTML"},
         'B'},

        {"Which data structure uses FIFO?",
         {"A. Stack", "B. Queue", "C. Tree", "D. Graph"},
         'B'}
    };

    int score = 0;
    char userAnswer;

    int lifeline50 = 1, audience = 1, call = 1;

    printf("team suhani\n");

    printf("Welcome to KBC Quiz Game \n");

    printf("------------------------------------\n");

  for (int i = 0; i < 5; i++) {

        printf("\nQ%d: %s\n", i + 1, q[i].question);

        for (int j = 0; j < 4; j++) {
            printf("%s\n", q[i].options[j]);
        }

        printf("\nEnter A/B/C/D or L for lifeline: ");
        scanf(" %c", &userAnswer);

        if(userAnswer>='a'&& userAnswer<='z'){
            userAnswer = userAnswer - 32;
        }

        // Lifeline section
        if (userAnswer == 'L') {

            printf("\nChoose Lifeline:\n");
            if (lifeline50) 
            printf("1. l5050\n");
            if (audience) 
            printf("2. Audience Poll\n");
            if (call)
             printf("3. Call a Friend\n");

            int choice;
            scanf("%d", &choice);

            int correctIndex = q[i].answer - 'A';

            if (choice == 1 && lifeline50) {
                int wrongIndex;

                srand(time(0));
                do {
                    wrongIndex = rand() % 4;
                } while (wrongIndex == correctIndex);

                printf("\n l5050 Options:\n");
                printf("%s\n", q[i].options[correctIndex]);
                printf("%s\n", q[i].options[wrongIndex]);

                lifeline50= 0;
            }

            else if (choice == 2 && audience) {
                printf("\n Audience Poll:\n");
                printf("A:20%%\n B:10%%\n C:60%%\n D: 10%%\n");

                audience = 0;
            }

            else if (choice == 3 && call) {
                printf("\nFriend is locking answer: %c\n", q[i].answer);

                call = 0;
            }

            else {
                printf("Invalid or already used!\n");
            }

            printf("\nNow enter your answer: ");
            scanf(" %c", &userAnswer);
            
        if(userAnswer>='a'&& userAnswer<='z'){
            userAnswer = userAnswer - 32;

        }
    }


        // Answer checking
        if (userAnswer == q[i].answer) {
            printf(" Correct!\n");
            score += 10;
        } else 
            printf("Wrong Answer! Game Over\n");
            break;
        }

        printf("Score: %d\n", score);

    printf("\n Final Score: %d\n", score);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>

int main() {
    int uchoice=0, cchoice=0, n = 1;
    const char *options[] = {"Rock", "Paper", "Scissors"};
    srand(time(NULL));
    time_t start, end;

    printf("About Game:\n");
    printf("This is a Rock-Paper-Scissors game made by Kali.\n");
    printf("\nHow to Play:\n");
    printf("\n•You will be given 3 options and you have to select one.\n");
    printf("•There is a time limit of 5 seconds and the game will continue until any one of the player Kali or You wins!\n\n");
    printf("•Press Enter to start the game!");

    while (getchar() != '\n');

     clrscr();
    printf("Options:\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    printf("Make choice within 5 sec or you lose!");
    printf("\nPress Enter when you're ready to choose!");

    while (getchar() != '\n');

    start = time(NULL);
    while (n) {
        printf("\nTime Left: ");
        for (int i = 5; i >= 0; i--) {
            printf("\rTime Left: %d", i);
            fflush(stdout);
            sleep(1);
            if (kbhit()) {
                uchoice = getch() - '0';
                break;
            }
            if (i == 0) {
                printf("\n\nTime Up! Don't cheat!");
                return 0;
            }
        }
        if (uchoice <= 0 || uchoice > 3) {
            printf("\n\nInvalid Choice Akal ke Andhe");
            return 0;

        }

        cchoice = rand() % 3;
        printf("\n\nYour choice: %s", options[uchoice - 1]);
        printf("\nComputer's choice: %s", options[cchoice]);

        printf("\n");
        if (uchoice == cchoice+1) {
            printf("\nIt's a tie!\n");
            printf("\nContinue...!\n");
        } else if (uchoice  == 1 && cchoice+1 == 2) {
            printf("\nKali Wins!");
            n=0;
        } else if (uchoice == 2 && cchoice +1== 3) {
            printf("\nKali Wins!");
            n=0;
        } else if (uchoice  == 3 && cchoice +1 == 1) {
            printf("\nKali Wins!");
            n=0;
        } else {
            printf("\nYou Win!");
            n = 0;
        }

    }

    return 0;
}

/* A game of stone, scissors, paper. (2016-04-12) */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************************/
/* Function declarations */
/*************************/

int getUserInput(void);
void presentResult(int, int, int*const, int*const);

/****************/
/* Main program */
/****************/

int main()
{
    /* Variables for rounds, choices and points */
    int your_choice, computers_choice, your_points = 0, computers_points = 0, round = 1;
    /* Set at what point someone wins */
    const int WINNING_POINT = 10;
    /* String representations of the differnt choices you can make */
    const char *choices[] = {"stone", "scissors", "paper"};
    
    srand(time(NULL)); /* Randomize the rand() function */
    printf("*** STONE SCISSORS PAPER ***\n\nLet's play!\n(Enter 0 to end the game)\n\n");

    /* The game loop */
    while (your_points < WINNING_POINT && computers_points < WINNING_POINT)
    {
        printf("*** ROUND %d ***\n\n", round++); /* Present current round, then increment */

        /* Get user and computer choices */
        your_choice      = getUserInput();
        computers_choice = 1+(rand()%3); /* Let the computer choose a number between 1 and 3 */
        
        /* SELECT "0" TO END GAME */
        if (your_choice == 0)
        {
            printf("\n\n*** USER ENDED GAME ***\n\n");
            exit(0);
        }
        
        printf("You chose %s. ", choices[your_choice-1]);
        printf("The computer chose %s.\n", choices[computers_choice-1]);

        /* Check the result of each round and present the result */
        presentResult(your_choice, computers_choice, &your_points, &computers_points);
        
        printf("You have %d points. ", your_points);
        printf("Computer has %d points\n\n", computers_points);
    }
    
    /* When game loop exits, present the winner */
    if (your_points > computers_points)
    {
        printf("*** YOU WIN! ***\n");
    }
    else
    {
        printf("*** COMPUTER WINS! ***\n");
    }
    
	return 0;
}

/************************/
/* Function definitions */
/************************/

/* Prompt user for input and return the choice */
int getUserInput()
{
    int choice;
    while (1) /* Loop until user input is between 1-3 */
    {
        printf("Stone(1), Scissors(2) or Paper(3): ");
        scanf("%d", &choice);
        if (choice >= 0 && choice <= 3)
        {
            return choice; /* Return the choice on correct input */
        }
    }
}

/* Present the result of the current round and update points */
void presentResult(int p, int c, int *p_points, int *c_points)
{
    if (p == c)
    {
        /* It's a draw */
        printf("IT'S A DRAW!\n");
    }
    /*
     * With the order "stone, scissors, paper" the winning choice is always 
     * one before the other. Stone beats scissors, scissors beats paper and 
     * paper beats stone. So, to check if you win I check if modulus of your 
     * choice + 1 is equal to computer's choice.
     * */
    else if ((p+1)%3 == c%3)
    {
        /* You win this round */
        printf("YOU WON THIS ROUND :)\n");
        *p_points = *p_points + 1; /* Why doesn't ++ work? */
    }
    else
    {
        /* The computer wins this round */
        printf("YOU LOST THIS ROUND :(\n");
        *c_points = *c_points + 1; /* Why doesn't ++ work? */
    }
}

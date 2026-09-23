#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{

    int x = 13, y = 13;
    char move;
    int foodX = 16, foodY = 16;
    int score = 0;
    system("cls"); // Clears the console screen

    // Welcome message
    printf("========================================\n");
    printf("          WELCOME TO SNAKE GAME         \n");
    printf("========================================\n\n");

    printf("Eat the food (*) and increase your score!\n");
    printf("Don't hit the border!\n\n");

    printf("CONTROLS:\n");
    printf("U -> Move Up\n");
    printf("D -> Move Down\n");
    printf("L -> Move Left\n");
    printf("R -> Move Right\n");
    printf("Q -> Quit Game\n\n");

    printf("========================================\n");
    printf("       Press Enter to start the game\n");
    printf("========================================\n");

    getchar();

    system("cls");
    while (1)
    {

        // Size of border
        for (int i = 0; i < 30; i++)
        {

            for (int j = 0; j < 30; j++)
            {

                // Board of border
                if (i == 0 || i == 29 || j == 0 || j == 29)
                {
                    printf("#");
                }

                // Snake
                else if (i == y && j == x)
                {
                    printf("O");
                }

                // Food
                else if (i == foodY && j == foodX)
                {
                    printf("*");
                }

                else
                {
                    printf(" ");
                }
            }

            printf("\n");
        }

        // Game over condition
        if (x <= 0 || x >= 29 || y <= 0 || y >= 29)
        {
            printf("Game Over ^_^\n Final Score: %d\n Thanks for playing ^_^\n", score);
            break;
        }

        // Prints score
        score = (x == foodX && y == foodY) ? score + 1 : score;

        printf("\nScore: %d\n", score);

        // After eating food the position of food will change

        if (x == foodX && y == foodY)
        {
            foodX = 1 + rand() % 28;
            foodY = 1 + rand() % 28;
        }

        // Taking input
        printf("Enter U/D/L/R to move (Q to quit): ");
        scanf(" %c", &move);

        // For moving
        if (move == 'U')
        {
            y--;
        }
        else if (move == 'D')
        {
            y++;
        }
        else if (move == 'L')
        {
            x--;
        }
        else if (move == 'R')
        {
            x++;
        }
        else if (move == 'Q')
        {
            break;
        }
    }

    return 0;
}

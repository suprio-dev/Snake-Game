#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15
#define MAX_SNAKE 100

int snakeX[MAX_SNAKE];
int snakeY[MAX_SNAKE];

int snakeLength;
int foodX;
int foodY;
int score;
int gameOver;

enum Direction
{
  UP,
  DOWN,
  LEFT,
  RIGHT
};

enum Direction direction;

void clearScreen()
{
  system("cls");
}

void spawnFood()
{
  int valid;
  do
  {
    valid = 1;
    foodX = rand() % WIDTH;
    foodY = rand() % HEIGHT;

    for (int i = 0; i < snakeLength; i++)
    {
      if (snakeX[i] == foodX && snakeY[i] == foodY)
      {
        valid = 0;
        break;
      }
    }
  } while (!valid);
}

void initializeGame()
{
  snakeLength = 3;
  snakeX[0] = WIDTH / 2;
  snakeY[0] = HEIGHT / 2;

  snakeX[1] = snakeX[0] - 1;
  snakeY[1] = snakeY[0];

  snakeX[2] = snakeX[0] - 2;
  snakeY[2] = snakeY[0];

  direction = RIGHT;

  score = 0;
  gameOver = 0;

  spawnFood();
}

void draw()
{
  clearScreen();
  printf("Score : %d\n\n", score);

  for (int y = -1; y <= HEIGHT; y++)
  {
    for (int x = -1; x <= WIDTH; x++)
    {
      if (x == -1 || x == WIDTH || y == -1 || y == HEIGHT)
      {
        printf("##");
        continue;
      }

      if (x == foodX && y == foodY)
      {
        printf("[]");
        continue;
      }

      int printed = 0;
      for (int i = 0; i < snakeLength; i++)
      {
        if (snakeX[i] == x && snakeY[i] == y)
        {
          if (i == 0)
            printf("OO");
          else
            printf("oo");
          printed = 1;
          break;
        }
      }
      if (!printed)
        printf("  ");
    }
    printf("\n");
  }

  printf("\n");
  printf("+----------------------------------+\n");
  printf("|          CONTROLS                |\n");
  printf("|                                  |\n");
  printf("|     W A S D  =  MOVE             |\n");
  printf("|       Q      =  QUIT             |\n");
  printf("+----------------------------------+\n");
}

void handleInput()
{
  if (!_kbhit())
  {
    return;
  }
  char input = _getch();
  if (input == 'q' || input == 'Q')
  {
    gameOver = 1;
  }
  if ((input == 'w' || input == 'W') && direction != DOWN)
  {
    direction = UP;
  }
  if ((input == 'a' || input == 'A') && direction != RIGHT)
  {
    direction = LEFT;
  }
  if ((input == 's' || input == 'S') && direction != UP)
  {
    direction = DOWN;
  }
  if ((input == 'd' || input == 'D') && direction != LEFT)
  {
    direction = RIGHT;
  }
}

void moveSnake()
{
  for (int i = snakeLength - 1; i > 0; i--)
  {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }
  if (direction == UP)
    snakeY[0]--;
  else if (direction == DOWN)
    snakeY[0]++;
  else if (direction == LEFT)
    snakeX[0]--;
  else if (direction == RIGHT)
    snakeX[0]++;

  // wrap around Horizontally
  if (snakeX[0] < 0)
    snakeX[0] = WIDTH - 1;
  else if (snakeX[0] >= WIDTH)
    snakeX[0] = 0;

  // wrap around Vertically
  if (snakeY[0] < 0)
    snakeY[0] = HEIGHT - 1;
  else if (snakeY[0] >= HEIGHT)
    snakeY[0] = 0;
}

void checkcollision()
{
  for (int i = 1; i < snakeLength; i++)
  {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
    {
      gameOver = 1;
      return;
    }
  }
}

void checkFood()
{
  if (snakeX[0] == foodX && snakeY[0] == foodY)
  {
    if (snakeLength < MAX_SNAKE)
    {
      snakeLength++;
    }
    score += 10;
    spawnFood();
  }
}

int main()
{
  srand(time(NULL));
  initializeGame();
  while (!gameOver)
  {
    draw();
    handleInput();
    moveSnake();
    checkcollision();
    if (!gameOver)
    {
      checkFood();
    }
    Sleep(120);
  }
  clearScreen();

  printf("\n");
  printf("        +--------------------------+\n");
  printf("        |        GAME OVER!        |\n");
  printf("        +--------------------------+\n");
  printf("        |                          |\n");
  printf("        |     SCORE : %-10d        |\n", score);
  printf("        |                          |\n");
  printf("        |    THANKS FOR PLAYING!   |\n");
  printf("        +--------------------------+\n");
  return 0;
}
#include "../includes/hanoi.h"

static int ft_clear(void)
{
    int status;
    char *args[] = {"clear", NULL};
    usleep(500000);
    if (fork() == 0)
    {
        if (execvp("clear", args) == -1)
            perror("Erreur lors de l'exécution de clear");
        exit(1);
    }
    wait(&status);
}
static void last_line(void)
{
    int i = 0;

    while (i < 39)
    {
        printf("#");
        i++;
    }
    printf("\n");
}

static void first_line(int l)
{
    int i = 0;

    while (3 > i++)
        printf("                                       \n");
    i = 0;
    while (l > i++)
        printf("      |            |            |      \n");  
}

static void display_line(int **game, int floor)
{
    int i = 0;
    int j = floor;

    while (--j >= 0)
    {
        while (i < 3)
        {
            if (game[i][j] > 0)
            {
                n_putchar(' ', 5 - (game[i][j] - 1));
                n_putchar('=', ((game[i][j] - 1) * 2) + 3);
                n_putchar(' ', 5 - (game[i][j] - 1));
            }
            else 
                printf("      |      ");
            i++;
        }
        i = 0;
        printf("\n");
    }
}

int display_game(int **game, int floor)
{
    // ft_clear();
    first_line(5 - floor);
    display_line(game, floor);
    last_line();
}

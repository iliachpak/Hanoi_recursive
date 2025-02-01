#include "../includes/hanoi.h"

int **alloc_game(int floor)
{
    int ** ret;
    int i = 0;

    ret = malloc(3 * sizeof(int *));
    if (!ret)
        return NULL; 
    while (i <= RIGTH)
    {
        ret[i] = malloc(floor * sizeof(int));
        if (!ret[i])
            return NULL;
        i++;
    }
    return (ret);
}

int set_game(int **game, int floor, e_peg peg)
{
    int i = 0;
    int j = 0;

    while (j <= RIGTH)
    {
        while (i < floor)
        {
            if (j == peg)
                game[j][i] = floor - i;
            else 
                game[j][i] = 0;
            i++;
        }
        i = 0;
        j++;
    }
}

int free_game(int **game)
{
    int i = 0;

    while (i < 3)
    {
        free(game[i]);
        i++;
    }
    free(game);
    return (0);
}
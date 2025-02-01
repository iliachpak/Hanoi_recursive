#include "../includes/hanoi.h"

int is_complete(int *peg, int floor)
{
    int i = 0;
    int last_floor = floor;

    while (i < floor)
    {
        if (peg[i] != last_floor - i)
            return (0);
        i++;
    }
    return (1);
}

int first_floor(int *peg, int floor)
{
    int i = 1;

    while (i < floor)
    {
        if (peg[floor - i] != 0)
            return i;
        i++;
    }
    return i;
}

void n_putchar(char c, int times)
{
    int i = 0;

    while (i < times)
    {
        printf("%c", c);
        i++;
    }
}
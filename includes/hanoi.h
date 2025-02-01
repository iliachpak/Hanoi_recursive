#ifndef __HANOI__
# define __HANOI__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

typedef enum {
    LEFT,
    MID,
    RIGTH
}   e_peg;

/******************************/
//----------GAME--------------//
/******************************/
int     **alloc_game(int floor);
int     set_game(int **game, int floor, e_peg peg);
int     free_game(int **game);

/******************************/
//---------DISPLAY------------//
/******************************/

void n_putchar(char c, int times);
int is_complete(int *peg, int floor);
int first_floor(int *peg, int floor);
int display_game(int **game, int floor);

/******************************/
//----------MAIN--------------//
/******************************/

#endif
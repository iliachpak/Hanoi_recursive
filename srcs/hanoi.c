#include "../includes/hanoi.h"

int top_toward_new_peg(int **game, int floor, e_peg peg)
{
    int i = 1;
    int j = 1;
    e_peg new_peg;

    new_peg = peg;
    i = first_floor(game[peg], floor);
    if (i == floor)
        return 0;
    for (int m = 0; m < 2; m++)
    {
        new_peg = (new_peg + 1)%3;
        j = first_floor(game[new_peg], floor);
        if ((j == floor && ((game[new_peg][floor - j] > game[peg][floor - i]) || game[new_peg][floor - j] == 0))
            || (game[new_peg][floor - j] > game[peg][floor - i]))
        {
            if (j == floor && game[new_peg][floor - j] == 0)
                game[new_peg][floor - j] = game[peg][floor - i];
            else
                game[new_peg][floor - j + 1] = game[peg][floor - i];
            game[peg][floor - i] = 0;
            return 1;
        }
        j = 1;
    }
    return 0;   
}

int solve_hanoi(int **game, int floor, e_peg peg)
{
    int i = first_floor(game[peg], floor);
    if (game[peg][floor - i] == floor)
        return 1;
    while (top_toward_new_peg(game, floor, peg));

    if (game[peg][0] == 0);
        return solve_hanoi(game, floor, (peg + 2)%3);
    return solve_hanoi(game, floor, (peg + 1)%3);
}

int main(int ac, char **av)
{
    int floor;
    int **game;
    e_peg peg = LEFT;
    int i = 0;

    if (ac != 2)
        return (1);
    floor = atoi(av[1]);
    if (floor < 2)
        return printf("tower is always finished.\n");
    else if (floor > 5)
        return printf("Too much floors for display.\n");

    game = alloc_game(floor);
    set_game(game, floor, peg);
    solve_hanoi(game, floor, peg);
    // while(top_toward_new_peg(game, floor, peg));

    display_game(game, floor);

    free_game(game);
    return (0);
}


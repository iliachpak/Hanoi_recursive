/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanoi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:41 by ichpakov          #+#    #+#             */
/*   Updated: 2025/02/08 17:38:07 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hanoi.h"

int move_floors_on_peg(int **game, int floors, int n, e_peg dst)
{
    e_peg src;
    int xy[2];
    int fst_ept_floor;

    find_disk(game, n, floors, xy);
    src = xy[0];
    fst_ept_floor = first_empty_floor(game[src], floors);
    if (n == 1)
    {
        fst_ept_floor = first_empty_floor(game[dst], floors);
        game[xy[0]][xy[1]] = 0;
        game[dst][floors - fst_ept_floor] = n;
        display_game(game, floors);
        return 1;
    }
    if (game[src][floors - fst_ept_floor - 1] != n)
        move_floors_on_peg(game, floors, game[src][xy[1] + 1], (3 - dst - src));
    fst_ept_floor = first_empty_floor(game[dst], floors);
    game[xy[0]][xy[1]] = 0;
    game[dst][floors - fst_ept_floor] = n;
    display_game(game, floors);
    return move_floors_on_peg(game, floors, n - 1, dst);    
}

int main(int ac, char **av)
{
    int floors;
    int **game;
    e_peg peg = LEFT;
    int i = 0;

    if (ac != 2)
        return (1);
    if (!parse(av[1]))
        return (1);
    floors = atoi(av[1]);
    if (floors < 2)
        return printf("tower is always finished.\n");
    else if (floors > 20)
        return printf("%d floors...its work but...please dont abuse.\n", floors);
    game = alloc_game(floors);
    set_game(game, floors, peg);
    display_game(game, floors);
    move_floors_on_peg(game, floors, floors, (peg + 2)%3);
    display_game(game, floors);
    printf("\nGame are solved !\n\n");
    free_game(game);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:32 by ichpakov          #+#    #+#             */
/*   Updated: 2025/02/07 18:02:22 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hanoi.h"

int **alloc_game(int floors)
{
    int ** ret;
    int i = 0;

    ret = malloc(3 * sizeof(int *));
    if (!ret)
        return NULL; 
    while (i <= RIGTH)
    {
        ret[i] = malloc(floors * sizeof(int));
        if (!ret[i])
            return NULL;
        i++;
    }
    return (ret);
}

void set_game(int **game, int floors, e_peg peg)
{
    int i = 0;
    int j = 0;

    while (j <= RIGTH)
    {
        while (i < floors)
        {
            if (j == peg)
                game[j][i] = floors - i;
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
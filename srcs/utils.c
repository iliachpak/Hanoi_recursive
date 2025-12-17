/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:44 by ichpakov          #+#    #+#             */
/*   Updated: 2025/02/07 17:56:45 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hanoi.h"

int first_empty_floor(int *peg, int floors)
{
    int i = 1;

    while (i <= floors)
    {
        if (peg[floors - i] != 0)
        {
            i--;
            return i;
        }
        i++;
    }
    i--;
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

void find_disk(int **game, int disk, int floors, int *xy)
{
    xy[0] = 0;
    xy[1] = 0;
    while (xy[0] < 3)
    {
        while (xy[1] < floors)
        {
            if (game[xy[0]][xy[1]] == disk)
                return;
            xy[1]++;
        }
        xy[1] = 0;
        xy[0]++;
    }
}

int parse(char *str)
{
    int i;

    i = 0;
    while (str[i] && isdigit(str[i]))
        i++;
    if (str[i])
        return 0;
    return 1;
}
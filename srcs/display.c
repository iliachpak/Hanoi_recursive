/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:56:35 by ichpakov          #+#    #+#             */
/*   Updated: 2025/02/08 17:37:58 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hanoi.h"

static void ft_clear(int floors)
{
    int status;
    char *args[] = {"clear", NULL};
    usleep(100000);
    if (fork() == 0)
    {
        if (execvp("clear", args) == -1)
            perror("Erreur lors de l'exécution de clear");
        exit(1);
    }
    wait(&status);
}

static void last_line(int floors)
{
    int i = 0;
    int end = (floors * 2 + 3)*3;

    while (i < end)
    {
        printf("#");
        i++;
    }
    printf("\n");
}

static void display_line(int **game, int floors)
{
    int i = 0;
    int j = floors;

    while (--j >= 0)
    {
        while (i < 3)
        {
            if (game[i][j] > 0)
            {
                n_putchar(' ', floors - (game[i][j] - 1));
                n_putchar('=', ((game[i][j] - 1) * 2) + 3);
                n_putchar(' ', floors - (game[i][j] - 1));
            }
            else 
            {
                n_putchar(' ', floors + 1);
                n_putchar('|', 1);
                n_putchar(' ', floors + 1);
            }
            i++;
        }
        i = 0;
        printf("\n");
    }
}

void display_game(int **game, int floors)
{
    ft_clear(floors);
    display_line(game, floors);
    last_line(floors);
}

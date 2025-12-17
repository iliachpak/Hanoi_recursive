/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanoi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:01:16 by ichpakov          #+#    #+#             */
/*   Updated: 2025/02/07 18:02:09 by ichpakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HANOI__
# define __HANOI__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
#include <math.h>

typedef enum {
    LEFT,
    MID,
    RIGTH
}   e_peg;

////////////////////////////////////////////////////////////////////////////////
//		GAME
////////////////////////////////////////////////////////////////////////////////
int     **alloc_game(int floors);
void     set_game(int **game, int floors, e_peg peg);
int     free_game(int **game);

////////////////////////////////////////////////////////////////////////////////
//		DISPLAY
////////////////////////////////////////////////////////////////////////////////

void display_game(int **game, int floors);

////////////////////////////////////////////////////////////////////////////////
//		UTILS
////////////////////////////////////////////////////////////////////////////////

void n_putchar(char c, int times);
int first_empty_floor(int *peg, int floors);
void find_disk(int **game, int disk, int floors, int *xy);
int parse(char *str);


#endif
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichpakov <ichpakov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 04:13:09 by ichpakov          #+#    #+#              #
#    Updated: 2025/02/07 18:00:43 by ichpakov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re make norm

NAME = hanoi

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS =	srcs/hanoi.c srcs/game.c srcs/display.c	srcs/utils.c

HEAD =	includes/hanoi.h

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = #-fsanitize=address -static-libasan -g #-Wall -Werror -Wextra
CI = -I ./includes/


AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${SRCS} ${HEAD}
	${CC} ${CI} ${SRCS} ${CF} -o ${NAME}

# Mandatory rules

clean:
	${RM}

fclean: clean
	${RM} ${NAME}

re: fclean all
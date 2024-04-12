# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namalier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 17:11:12 by namalier          #+#    #+#              #
#    Updated: 2024/04/11 19:11:42 by namalier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= Moves/moves1.c lib/ft_lib.c lib/ft_lib_utils.c lib/ft_lst.c \
			Moves/moves2.c Moves/moves3.c push_swap.c ft_error.c Algo/algo.c \
			Algo/check_algo.c Algo/count.c Algo/moves_algo.c \
			Algo/move_top_bot.c Algo/moves_algo2.c Algo/moves_algo3.c \
			Algo/count2.c \

SRCS_BONUS	= Moves/moves1.c Moves/moves2.c Moves/moves3.c lib/ft_lib.c \
			  lib/ft_lib_utils.c lib/ft_lst.c ft_error.c Bonus/checker.c \
			  Bonus/checker_bonus.c Bonus/GNL/get_next_line.c \
			  Bonus/GNL/get_next_line_utils.c

HEADER		= push_swap.h

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= push_swap

NAME_BONUS	= checker

CFLAGS		= -Wall -Werror -Wextra

.c.o		:
			cc ${CFLAGS} -c $< -o ${<:.c=.o} -g

${NAME}		:    ${OBJS}
			cc ${OBJS} -o ${NAME} -g

all			:		${NAME}

clean		:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean		:		clean
			rm -f ${NAME} ${NAME_BONUS}

re			: fclean all

checker		:	${OBJS_BONUS}
			cc ${OBJS_BONUS} -o ${NAME_BONUS} -g

.PHONY		: all clean fclean re checker

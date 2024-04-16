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

SRCS		= srcs/Mandatory/Moves/moves1.c Mandatory/lib/ft_lib.c \
			Mandatory/lib/ft_lib_utils.c Mandatory/lib/ft_lst.c \
			Mandatory/Moves/moves2.c Mandatory/Moves/moves3.c \
			Mandatory/push_swap.c Mandatory/ft_error.c Algo/algo.c \
			Mandatory/Algo/check_algo.c Mandatory/Algo/count.c \
			Mandatory/Algo/moves_algo.c Mandatory/Algo/move_top_bot.c \
			Mandatory/Algo/moves_algo2.c Mandatory/Algo/moves_algo3.c \
			Mandatory/Algo/count2.c \

SRCS_BONUS	= Mandatory/Moves/moves1.c Mandatory/Moves/moves2.c \
			  Mandatory/Moves/moves3.c Mandatory/lib/ft_lib.c \
			  Mandatory/lib/ft_lib_utils.c Mandatory/lib/ft_lst.c \
			  Mandatory/ft_error.c Bonus/checker.c Bonus/parsing_bonus.c \
			  Bonus/GNL/get_next_line.c Bonus/GNL/get_next_line_utils.c \

HEADER		= push_swap.h

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= push_swap

NAME_BONUS	= checker

CFLAGS		= -Wall -Werror -Wextra -I include

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

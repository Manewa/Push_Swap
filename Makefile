# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namalier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 17:11:12 by namalier          #+#    #+#              #
#    Updated: 2024/02/09 17:11:13 by namalier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= Moves/moves1.c lib/ft_lib.c lib/ft_lib_utils.c lib/ft_lst.c \
			Moves/moves2.c Moves/moves3.c push_swap.c ft_error.c Algo/algo.c 

HEADER		= push_swap.h

OBJS		= ${SRCS:.c=.o}

NAME		= push_swap

CFLAGS		= -Wall -Werror -Wextra

.c.o		:
			cc ${CFLAGS} -c $< -o ${<:.c=.o} -g

${NAME}		:    ${OBJS}
			cc ${OBJS} -o ${NAME} -g

all			:		${NAME}

clean		:
			rm -f ${OBJS}

fclean		:		clean
			rm -f ${NAME}

re			: fclean all

.PHONY		: all clean fclean re

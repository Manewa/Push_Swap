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

SRCS		= moves.c ft_lib.c ft_lib_utils.c ft_lst.c moves_reverse.c \
			push_swap.c 

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

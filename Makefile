# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: namalier <namalier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:49:35 by namalier          #+#    #+#              #
#    Updated: 2024/04/25 17:03:38 by namalier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALGODIR			= srcs/Mandatory/Algo
LIBDIR 			= srcs/Mandatory/lib
MOVESDIR 		= srcs/Mandatory/Moves
BONUSDIR		= srcs/Bonus
GNLDIR			= srcs/Bonus/GNL
OBJDIR 			= obj
OBJDIRBNS		= obj_bonus

SRCS 			= $(ALGODIR)/algo.c $(ALGODIR)/check_algo.c $(ALGODIR)/count.c \
				srcs/Mandatory/push_swap.c $(ALGODIR)/count_order.c \
				$(ALGODIR)/find_extrems.c $(ALGODIR)/move_top_bot.c \
				$(ALGODIR)/moves_a.c $(ALGODIR)/moves_b.c $(ALGODIR)/moves_r.c \
				$(LIBDIR)/ft_lib_utils.c $(LIBDIR)/ft_error.c $(LIBDIR)/ft_lib.c \
				$(LIBDIR)/ft_lst.c $(MOVESDIR)/moves1.c $(MOVESDIR)/moves2.c \
				$(MOVESDIR)/moves3.c \

SRCS_BONUS		= $(MOVESDIR)/moves1.c $(MOVESDIR)/moves2.c \
				$(MOVESDIR)/moves3.c $(LIBDIR)/ft_lib_utils.c \
				$(LIBDIR)/ft_error.c $(LIBDIR)/ft_lib.c $(LIBDIR)/ft_lst.c \
				$(GNLDIR)/get_next_line.c $(GNLDIR)/get_next_line_utils.c \
				$(BONUSDIR)/checker.c $(BONUSDIR)/parsing_bonus.c \

OBJS 			=	$(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SRCS)))

OBJS_BONUS		=	$(patsubst %.c,$(OBJDIRBNS)/%.o,$(notdir $(SRCS_BONUS)))

NAME			=	push_swap

NAME_BONUS		=	checker

CFLAGS			=	-Wall -Werror -Wextra -I include

$(NAME)			:	$(OBJDIR) $(OBJS)
				cc $(OBJS) $(CFLAGS) -o $(NAME) -g

$(NAME_BONUS)		: 	$(OBJDIRBNS) $(OBJS_BONUS)
				cc $(OBJS_BONUS) $(CFLAGS) -o $(NAME_BONUS) -g

$(OBJDIR)		:
	 			@mkdir -p $@

$(OBJDIRBNS)	:
				@mkdir -p $@

$(OBJDIR)/%.o	:	$(ALGODIR)/%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o	:	$(LIBDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o	:	$(MOVESDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIR)/push_swap.o	: srcs/Mandatory/push_swap.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIRBNS)/%.o: $(MOVESDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIRBNS)/%.o: $(LIBDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIRBNS)/%.o: $(GNLDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

$(OBJDIRBNS)/%.o: $(BONUSDIR)/%.c
				cc $(CFLAGS) -c $< -o $@

bonus			: $(NAME_BONUS)

clean			:
				rm -rf $(OBJDIR) $(OBJDIRBNS)

fclean			:	clean
				rm -rf $(NAME) $(NAME_BONUS)

re				: fclean all

all				: $(NAME)

.PHONY			: all clean fclean re bonus

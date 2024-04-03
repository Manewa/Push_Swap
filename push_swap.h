/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:14:23 by namalier          #+#    #+#             */
/*   Updated: 2024/02/09 16:14:24 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stddef.h>
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>

typedef struct s_list
{
	int				content;
	int				ra;
	int				rra;
	int				rb;
	int				rrb;
	int				rr;
	int				rrr;
	int				addr;
	int				count_move;
	struct s_list	*next;
}					t_list;

/********			ft_lib_utils			******/

size_t		ft_strlen(const char *c);
int			ft_count_word(char const *s, char c);
char		*ft_cpy_str(char *str, char const *s, size_t *i, char c);
void		ft_free(char **str, char const *s, char c);

/********			ft_error				******/

void		ft_exit(void);
void		ft_num(char **str);
void		ft_sign(char **str);
int			ft_check_double(long int *num);
void		ft_check_errors(char **str);

/********			moves1					******/

void		sa(t_list **n, int yn);
void		ss(t_list **a, t_list **b);
void		pa(t_list **top, t_list **del);
void		ra(t_list **n, int yn);
void		rr(t_list **a, t_list **b);

/********			moves2					******/

void		rra(t_list **n, int yn);
void		rrr(t_list **a, t_list **b);
void		sb(t_list **n, int yn);
void		pb(t_list **top, t_list **del);
void		rb(t_list **n, int yn);

/********			moves3					******/

void		rrb(t_list **n, int yn);

/********			ft_lst					******/

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstfree(t_list **a);

/********			ft_lib					******/

long int	ft_atoi(const char *str);
char		*ft_strjoin(char *s1, char const *s2, size_t entry);
char		**ft_split(char const *s, char c);

/********			push_swap				******/

void		lstcreate(t_list **a, long int *split);
long int	*ft_parse(int argc, char **argv);
int			main(int argc, char **argv);

/********			algo					******/

void		count_move_rrr(t_list **search);
void		main_algo(t_list **a);
void		fill_b(t_list **a, t_list **b);

/********			check_algo				******/

int			sorted(t_list **a);
t_list		*check_highest_lowest(t_list **search_a, t_list **head_b);
t_list		*check_pos_a(t_list **search_a, t_list **head_b);

/********			count					******/

void		count_a(t_list **head);
void		count_moves(t_list **head_a);
void		count_b(t_list **head_a, t_list **head_b);
void		find_pass(t_list **head_a, t_list **pass);
void		count_rrr(t_list **search);

/********			moves_algo				******/

void		position_b(t_list **head_b, t_list **pass);
void		pass_to_b(t_list **head_a, t_list **b, t_list **pass);
void		pass_to_a(t_list **head_a, t_list **head_b);
void		count_order(t_list **head_b);
void		move_to_max(t_list **head_b, int rb, int rrb);

/********			moves_algo2				******/

void		move_rrr(t_list **head_a, t_list **head_b, t_list **pass);
long int	lowest_all(t_list **head_a, t_list **head_b);
long int	highest_all(t_list **head_a, t_list **head_b);
void		under_five(t_list **head_a, t_list **head_b);
void		sort_b_under_five(t_list **head_b);

/********			move_top_bot			******/

int			find_lowest(t_list **head_b);
int			find_highest(t_list **head_b);
void		a_to_lowest(t_list **head);
void		pass_to_highest(t_list **pass, t_list **b);
void		sort_a_at_three(t_list **head_a);

/********************TESTS A SUPPRIMER************/

void		ft_testlst(t_list **a, t_list **b);

#endif

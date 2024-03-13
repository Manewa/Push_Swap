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
	int				move_up;
	int				move_down;
	int				rb;
	int				rrb;
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

t_list		**main_algo(t_list **a);
void		fill_b(t_list **a, t_list **b);

/********			check_algo				******/

int			sorted(t_list **a);

/********			count					******/

void		count_a(t_list **head);
void		count_moves(t_list **head_a);
void		count_b(t_list **head_a, t_list **head_b);

/********************TESTS A SUPPRIMER************/

void		ft_testlst(t_list **a, t_list **b);

#endif

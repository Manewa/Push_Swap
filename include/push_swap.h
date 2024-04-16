/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:14:23 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:39:33 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs.h"

/********			ft_lib_utils		******/

size_t		ft_strlen(const char *c);
int			ft_count_word(char const *s, char c);
char		*ft_cpy_str(char *str, char const *s, size_t *i, char c);
void		ft_free(char **str, char const *s, char c);
char		*ft_strdup(const char *str);

/********			ft_error			******/

void		ft_exit(void);
void		ft_num(char **str);
void		ft_sign(char **str);
int			ft_check_double(long int *num);
void		ft_check_errors(char **str);

/********			moves1				******/

void		sa(t_list **n, int yn);
void		ss(t_list **a, t_list **b, int yn);
void		pa(t_list **top, t_list **del, int yn);
void		ra(t_list **n, int yn);
void		rr(t_list **a, t_list **b, int yn);

/********			moves2				******/

void		rra(t_list **n, int yn);
void		rrr(t_list **a, t_list **b, int yn);
void		sb(t_list **n, int yn);
void		pb(t_list **top, t_list **del, int yn);
void		rb(t_list **n, int yn);

/********			moves3				******/

void		rrb(t_list **n, int yn);

/********			ft_lst				******/

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
int			ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstfree(t_list **a);

/********			ft_lib				******/

long int	ft_atoi2(const char *str, int i, int j, int sign);
long int	ft_atoi(const char *str);
char		*ft_strjoin(char *s1, char const *s2, size_t entry);
char		**ft_split(char const *s, char c);

/********			push_swap			******/

long int	*ft_parse_add(char **split, char *str, long int *num);
long int	*ft_parse(int argc, char **argv);
void		lstcreate(t_list **a, long int *split);
int			main(int argc, char **argv);

/********			algo				******/

int			prepare_for_algo(t_list **a, t_list **b);
void		fill_b(t_list **a, t_list **b);
void		main_algo(t_list **a);

/********			check_algo			******/

int			sorted(t_list **a);
t_list		*check_pos_a(t_list **search_a, t_list **head_b);

/********			count				******/

void		count_a(t_list **head);
void		count_b(t_list **head_a, t_list **head_b);
void		count_moves(t_list **head_a);
void		find_pass(t_list **head_a, t_list **pass);

/********			count_order			******/

void		count_order(t_list **head_b);
void		count_order_a(t_list **head_a);

/********			find_extrems		******/

t_list		*check_highest_lowest(t_list **search_a, t_list **head_b);
int			find_lowest(t_list **head_b);
int			find_highest(t_list **head_b);

/*********			move_top_bot		******/

void		move_to_max(t_list **head_b, int rb, int rrb);
void		pass_to_highest(t_list **pass, t_list **b);
void		move_to_min(t_list **head_a, int mra, int mrra);

/********			moves_a				******/

void		move_to_a(t_list **head_a, t_list **head_b, t_list *tail);
void		pass_to_a(t_list **head_a, t_list **head_b);
void		sort_a_at_three(t_list **head_a);

/********			moves_b				******/

void		position_b(t_list **head_b, t_list **pass);
void		pass_to_b(t_list **head_a, t_list **b, t_list **pass);
void		sort_b_at_three(t_list **head_b);

/*********			moves_r				******/

void		count_r(t_list **search, int countra, int countrb);
void		count_rrr(t_list **search);
void		count_move_rrr(t_list **search);
void		move_rrr(t_list **head_a, t_list **head_b, t_list **pass);

/********			checker				******/

int			moves_algo(t_list **head_a, t_list **head_b, char *m);
int			checker_algo(t_list **a, t_list **b, char **moves, char *move);
void		lstcreate_bonus(t_list **a, long int *split);
int			checker(char **moves, char *move, long int *split);
int			main(int argc, char **argv);

/********			checker_bonus		*******/

char		*ft_strjoin_bonus(char *s1, char const *s2);
char		*join_move(void);
int			parsing_bonus(char **move, char ***moves, long int *split);
long int	*ft_parse_add_bonus(char **split, char *str, long int *num);
long int	*ft_parse_bonus(int argc, char **argv);

/*********			GNL					*******/

char		*ft_gnldup(char *src);
char		*ft_gnlchr(char *str, int to_find);
char		*ft_gnljoin(char *s1, char *s2);
int			ft_gnllen(char *str);
int			ft_checkline(char *line);
void		ft_gnlmove(char *buf, char *line, size_t stop);
char		*ft_movenewline(char *line, char *buf, ssize_t nread, int fd);
char		*get_next_line(int fd);

#endif

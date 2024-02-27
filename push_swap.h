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

 #  include<stddef.h>
 #  include<stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

/********			moves					******/

void	swap_top(t_list **n);
void	dswap_top(t_list **a, t_list **b);
void	push_top(t_list **top, t_list **del);
void	rotate_up(t_list **n);
void	drotate_up(t_list **a, t_list **b);

/********			moves_reverse			******/

void	rev_rotate(t_list **n);
void	drev_rotate(t_list **a, t_list **b);

/********			ft_lst					******/

t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

/********			ft_lib					******/

int		ft_atoi(const char *str);
char	*ft_strjoin(char *s1, char const *s2, size_t entry);
char	**ft_split(char const *s, char c);

/********			ft_lib_utils			******/

size_t	ft_strlen(const char *c);
int		ft_count_word(char const *s, char c);
char	*ft_cpy_str(char *str, char const *s, size_t *i, char c);
void	ft_free(char **str, char const *s, char c);

/********			push_swap				******/

void	lstcreate(t_list **a, int *split);
int	*ft_parse(int argc, char **argv);
int main (int argc, char **argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:14:36 by namalier          #+#    #+#             */
/*   Updated: 2024/02/21 05:43:20 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **n, int yn)
{
	int	swap;

	swap = (*n)->content;
	(*n)->content = (*n)->next->content;
	(*n)->next->content = swap;
	if (yn == 1)
		write (1, "sa\n", 3);
	return ;
}

void	ss(t_list **a, t_list **b, int yn)
{
	sa(a, 0);
	sb(b, 0);
	if (yn == 1)
		write (1, "ss\n", 3);
	return ;
}

void	pa(t_list **top, t_list **del, int yn)
{
	t_list	*swap;

	if (!(*del)->content)
		return ;
	swap = *del;
	*del = (*del)->next;
	ft_lstadd_front(top, swap);
	if (yn == 1)
		write (1, "pa\n", 3);
	return ;
}

void	ra(t_list **n, int yn)
{
	t_list	*swap;

	swap = (*n);
	*n = (*n)->next;
	swap->next = NULL;
	ft_lstadd_back(n, swap);
	if (yn == 1)
		write (1, "ra\n", 3);
	return ;
}

void	rr(t_list **a, t_list **b, int yn)
{
	ra(a, 0);
	rb(b, 0);
	if (yn == 1)
		write (1, "rr\n", 3);
	return ;
}

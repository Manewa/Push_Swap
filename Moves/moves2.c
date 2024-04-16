/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 05:31:25 by namalier          #+#    #+#             */
/*   Updated: 2024/03/05 16:12:05 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **n, int yn)
{
	t_list	*swap;
	t_list	*tmp;

	if (!(*n) || !((*n)->next))
		return ;
	swap = (*n);
	if ((*n)->next->next == NULL)
		sa(n, 0);
	else
	{
		while (swap->next->next)
			swap = swap->next;
		tmp = swap;
		swap = swap->next;
		ft_lstadd_front(n, swap);
		tmp->next = NULL;
	}
	if (yn == 1)
		write (1, "rra\n", 4);
	return ;
}

void	rrr(t_list **a, t_list **b, int yn)
{
	rra(a, 0);
	rrb(b, 0);
	if (yn == 1)
		write (1, "rrr\n", 4);
	return ;
}

void	sb(t_list **n, int yn)
{
	int	swap;

	if (!(*n) || !((*n)->next))
		return ;
	swap = (*n)->content;
	(*n)->content = (*n)->next->content;
	(*n)->next->content = swap;
	if (yn == 1)
		write (1, "sb\n", 3);
	return ;
}

void	pb(t_list **top, t_list **del, int yn)
{
	t_list	*swap;

	if (!(*del))
		return ;
	swap = *del;
	*del = (*del)->next;
	ft_lstadd_front(top, swap);
	if (yn == 1)
		write (1, "pb\n", 3);
	return ;
}

void	rb(t_list **n, int yn)
{
	t_list	*swap;

	if (!(*n) || !((*n)->next))
		return ;
	swap = (*n);
	*n = (*n)->next;
	swap->next = NULL;
	ft_lstadd_back(n, swap);
	if (yn == 1)
		write (1, "rb\n", 3);
	return ;
}

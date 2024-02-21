/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:14:36 by namalier          #+#    #+#             */
/*   Updated: 2024/02/21 05:43:20 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list **n)
{
	int	swap;

	swap = (*n)->content;
	(*n)->content = (*n)->next->content;
	(*n)->next->content = swap;
	return ;
}

void	dswap_top(t_list **a, t_list **b)
{
	swap_top(a);
	swap_top(b);
	return ;
}

void	push_top(t_list **top, t_list **del)
{
	t_list	*swap;

	if (!(*del)->content)
		return ;
	swap = *del;
	*del = (*del)->next;
	ft_lstadd_front(top, swap);
	return ;
}

void	rotate_up(t_list **n)
{
	t_list	*swap;

	swap = (*n);
	*n = (*n)->next;
	swap->next = NULL;
	ft_lstadd_back(n, swap);
	return ;
}

void	drotate_up(t_list **a, t_list **b)
{
	rotate_up(a);
	rotate_up(b);
	return ;
}

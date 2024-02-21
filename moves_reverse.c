/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 05:31:25 by namalier          #+#    #+#             */
/*   Updated: 2024/02/21 05:31:27 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **n)
{
	t_list	*swap;
	t_list	*tmp;

	swap = (*n);
	if ((*n)->next->next == NULL)
		swap_top(n);
	else
	{
		while (swap->next->next)
			swap = swap->next;
		tmp = swap;
		swap = swap->next;
		ft_lstadd_front(n, swap);
		tmp->next = NULL;
	}
	return ;
}

void	drev_rotate(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	return ;
}

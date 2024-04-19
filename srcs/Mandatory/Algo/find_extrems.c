/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extrems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:02:43 by namalier          #+#    #+#             */
/*   Updated: 2024/04/19 16:53:13 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*check_highest_lowest(t_list **search_a, t_list **head_b)
{
	t_list	*search_b;

	search_b = *head_b;
	if ((*search_a)->content > find_highest(head_b))
	{
		while (search_b->content != find_highest(head_b))
		{
			(*search_a)->rb += 1;
			search_b = search_b->next;
		}
	}
	else if ((*search_a)->content < find_lowest(head_b))
	{
		while (search_b->content != find_lowest(head_b))
		{
			(*search_a)->rb += 1;
			search_b = search_b->next;
		}
		(*search_a)->rrb = -1;
		(*search_a)->rb += 1;
	}
	return (search_b);
}

int	find_highest(t_list **head_b)
{
	int		highest;
	t_list	*tmpb;

	tmpb = *head_b;
	highest = tmpb->content;
	while (tmpb->next)
	{
		tmpb = tmpb->next;
		if (highest < tmpb->content)
			highest = tmpb->content;
	}
	return (highest);
}

int	find_lowest(t_list **head_b)
{
	int		lowest;
	t_list	*tmpb;

	tmpb = *head_b;
	lowest = tmpb->content;
	while (tmpb->next)
	{
		tmpb = tmpb->next;
		if (lowest > tmpb->content)
			lowest = tmpb->content;
	}
	return (lowest);
}

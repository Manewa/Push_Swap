/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:36 by namalier          #+#    #+#             */
/*   Updated: 2024/03/25 12:54:37 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted(t_list **a)
{
	t_list	*move;

	move = *a;
	if (*a && (*a)->next && (!(*a)->next->next)
		&& (*a)->content > (*a)->next->content)
	{
		sa(a, 1);
		return (1);
	}
	while (move->next)
	{
		if (move->content > move->next->content)
			return (0);
		move = move->next;
	}
	return (1);
}

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

t_list	*check_pos_a(t_list **search_a, t_list **head_b)
{
	t_list	*search_b;

	search_b = *head_b;
	if ((*search_a)->content > search_b->content
		&& (*search_a)->content < ft_lstlast(*head_b)->content)
			(*search_a)->rb = 0;
	else
	{
		while (!((*search_a)->content < search_b->content
				&& (*search_a)->content > search_b->next->content))
		{
			(*search_a)->rb += 1;
			search_b = search_b->next;
		}
		(*search_a)->rb += 1;
		search_b = search_b->next;
	}
	return (search_b);
}

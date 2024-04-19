/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:08:43 by namalier          #+#    #+#             */
/*   Updated: 2024/04/19 16:54:24 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_order(t_list **head_b)
{
	t_list	*tmp_b;
	int		rb;
	int		rrb;
	int		highest;

	rb = 0;
	rrb = 0;
	tmp_b = *head_b;
	highest = find_highest(head_b);
	while (tmp_b->content != highest)
	{
		rb += 1;
		tmp_b = tmp_b->next;
	}
	while (tmp_b)
	{
		rrb += 1;
		tmp_b = tmp_b->next;
	}
	move_to_max(head_b, rb, rrb);
}

void	count_order_a(t_list **head_a)
{
	t_list	*tmp_a;
	int		ra;
	int		rra;
	int		lowest;

	ra = 0;
	rra = 0;
	tmp_a = *head_a;
	lowest = find_lowest(head_a);
	while (tmp_a->content != lowest)
	{
		ra += 1;
		tmp_a = tmp_a->next;
	}
	while (tmp_a)
	{
		rra += 1;
		tmp_a = tmp_a->next;
	}
	move_to_min(head_a, ra, rra);
}

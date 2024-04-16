/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:26 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:13:41 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_a(t_list **head)
{
	t_list	*search;
	t_list	*tmp;

	search = *head;
	search->rra = -1;
	while (search->rra != 1)
	{
		if (search->rra >= 0)
				search = search->next;
		tmp = *head;
		search->ra = 0;
		search->rra = 1;
		while (tmp->content != search->content)
		{
			search->ra = search->ra + 1;
			tmp = tmp->next;
		}
		while (tmp->next)
		{
			search->rra = search->rra + 1;
			tmp = tmp->next;
		}
	}
}

void	count_b(t_list **head_a, t_list **head_b)
{
	t_list	*search_a;
	t_list	*search_b;

	search_a = *head_a;
	while (search_a)
	{
		search_b = *head_b;
		search_a->rb = 0;
		search_a->rrb = 0;
		if (search_a->content > find_highest(head_b)
			|| search_a->content < find_lowest(head_b))
			search_b = check_highest_lowest(&search_a, head_b);
		else
			search_b = check_pos_a(&search_a, head_b);
		while (search_b)
		{
			search_a->rrb += 1;
			search_b = search_b->next;
		}
		count_rrr(&search_a);
		search_a = search_a->next;
	}
}

void	count_moves(t_list **head_a)
{
	t_list	*search;

	search = *head_a;
	while (search)
	{
		search->count_move = 0;
		if (search->rb <= search->rrb)
			search->count_move = search->rb;
		else
			search->count_move = search->rrb;
		if (search->ra <= search->rra)
			search->count_move += search->ra;
		else
			search->count_move += search->rra;
		count_move_rrr(&search);
		search = search->next;
	}
}


void	find_pass(t_list **head_a, t_list **pass)
{
	t_list	*tmp;

	*pass = *head_a;
	tmp = *head_a;
	while (tmp)
	{
		if ((*pass)->count_move > tmp->count_move)
			*pass = tmp;
		tmp = tmp->next;
	}
	return ;
}


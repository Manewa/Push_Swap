/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:26 by namalier          #+#    #+#             */
/*   Updated: 2024/03/25 12:54:27 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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


void	count_moves(t_list **head_a)
{
	t_list	*search;
	
	search = *head_a;
	while (search)
	{
		if (search->rb <= search->rrb)
		{
			if (search->ra <= search->rra)
				search->count_move = search->rb + search->ra;
			else
				search->count_move = search->rb + search->rra;
			}
		else
			{
				if (search->ra < search->rra)
					search->count_move = search->rrb + search->ra;
				else
					search->count_move = search->rrb + search->rra;	
			}
		count_move_rrr(&search);
		search = search->next;
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

void	count_rrr(t_list **search_a)
{
	t_list	*tmp_a;
	int		countra;
	int		countrb;

	tmp_a = *search_a;
	tmp_a->rr = 0;
	tmp_a->rrr = 0;
	if (tmp_a->ra <= tmp_a->rra && tmp_a->rb <= tmp_a->rrb)
	{
		countra = (*search_a)->ra;
		countrb = (*search_a)->rb;
		while (countra != 0 && countrb != 0)
		{
			countra -= 1;
			countrb -= 1;
			tmp_a->rr += 1;
		}
	}
	else if (tmp_a->rra <= tmp_a->ra && tmp_a->rrb <= tmp_a->rb)
	{
		countra = (*search_a)->rra;
		countrb = (*search_a)->rrb;
		while (countra != 0 && countrb != 0)
		{
			countra -= 1;
			countrb -= 1;
			tmp_a->rrr += 1;
		}
	}
}


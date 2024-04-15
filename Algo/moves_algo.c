/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:14 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:31:49 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	position_b(t_list **head_b, t_list **pass)
{
	if ((*pass)->rb >= (*pass)->rrb)
	{
		while ((*pass)->rrb != 0)
		{
			rrb(head_b, 1);
			(*pass)->rrb -= 1;
		}
	}
	else
	{
		while ((*pass)->rb != 0)
		{
			rb(head_b, 1);
			(*pass)->rb -= 1;
		}
	}
	return ;
}

void	pass_to_b(t_list **head_a, t_list **head_b, t_list **pass)
{
	if ((*pass)->addr == (*pass)->count_move)
		move_rrr(head_a, head_b, pass);
	if ((*pass)->ra >= (*pass)->rra)
	{
		while ((*pass)->rra != 0)
		{
			rra(head_a, 1);
			(*pass)->rra -= 1;
		}
	}
	else
	{
		while ((*pass)->ra != 0)
		{
			{
				ra(head_a, 1);
				(*pass)->ra -= 1;
			}
		}
	}
	position_b(head_b, pass);
	pb (head_b, head_a, 1);
	return ;
}

void	pass_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*tail;

	sort_a_at_three(head_a);
	if ((*head_b)->next && (*head_b)->content < (*head_b)->next->content)
		sb(head_b, 1);
	tail = NULL;
	move_to_a(head_a, head_b, tail);
}

void	move_to_max(t_list **head_a, int mra, int mrra)
{
	if (mra < mrra)
	{
		while (mra != 0)
		{
			rb(head_a, 1);
			mra -= 1;
		}
	}
	else
	{
		while (mrra != 0)
		{
			rrb(head_a, 1);
			mrra -= 1;
		}
	}
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_algo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:03:01 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:03:02 by namalier         ###   ########.fr       */
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

void	sort_b_at_three(t_list **head_b)
{
	if ((*head_b)->content == find_lowest(head_b)
		&& (*head_b)->next->content > (*head_b)->next->next->content)
		rb (head_b, 1);
	else if ((*head_b)->content == find_lowest(head_b)
		&& (*head_b)->next->content < (*head_b)->next->next->content)
	{
		sb(head_b, 1);
		rrb(head_b, 1);
	}
	else if ((*head_b)->next->content == find_lowest(head_b)
		&& (*head_b)->content > (*head_b)->next->next->content)
	{
		sb(head_b, 1);
		rb(head_b, 1);
	}
	else if ((*head_b)->next->content == find_lowest(head_b)
		&& (*head_b)->content < (*head_b)->next->next->content)
		rrb(head_b, 1);
	else if ((*head_b)->next->next->content == find_lowest(head_b)
		&& (*head_b)->content < (*head_b)->next->content)
		sb(head_b, 1);
	return ;
}
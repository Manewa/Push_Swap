/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_bot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:32:31 by namalier          #+#    #+#             */
/*   Updated: 2024/04/19 16:51:33 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	pass_to_highest(t_list **pass, t_list **b)
{
	t_list	*tmpb;

	tmpb = *b;
	(*pass)->rb = 0;
	(*pass)->rrb = 0;
	while (tmpb->next && tmpb->content > tmpb->next->content)
	{
		(*pass)->rb += 1;
		tmpb = tmpb->next;
	}
	if (tmpb->next)
		(*pass)->rb += 1;
	while (tmpb->next)
	{
		(*pass)->rrb += 1;
		tmpb = tmpb->next;
	}
	return ;
}

void	move_to_min(t_list **head_a, int mra, int mrra)
{
	if (mra < mrra)
	{
		while (mra != 0)
		{
			ra(head_a, 1);
			mra -= 1;
		}
	}
	else
	{
		while (mrra != 0)
		{
			rra(head_a, 1);
			mrra -= 1;
		}
	}
}

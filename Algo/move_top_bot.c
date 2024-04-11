/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_bot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:32:31 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:33:49 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_at_three(t_list **head_a)
{
	if ((*head_a)->content == find_lowest(head_a)
		&& (*head_a)->next->content > (*head_a)->next->next->content)
	{
		sa(head_a, 1);
		ra(head_a, 1);
	}
	else if ((*head_a)->next->content == find_lowest(head_a)
		&& (*head_a)->content > (*head_a)->next->next->content)
		ra(head_a, 1);
	else if ((*head_a)->next->content == find_lowest(head_a)
		&& (*head_a)->content < (*head_a)->next->next->content)
		sa(head_a, 1);
	else if ((*head_a)->next->next->content == find_lowest(head_a)
		&& (*head_a)->content > (*head_a)->next->content)
	{
		sa(head_a, 1);
		rra(head_a, 1);
	}
	else if ((*head_a)->next->next->content == find_lowest(head_a)
		&& (*head_a)->content < (*head_a)->next->content)
		rra(head_a, 1);
	return ;
}

void	a_to_lowest(t_list **head)
{
	int	lowest;
	int	i;

	i = 0;
	lowest = find_lowest(head);
	while ((*head)->next && (*head)->content != lowest)
		rra(head, 1);
	if ((*head)->next && (*head)->next->next
		&& (*head)->next->content > (*head)->next->next->content)
	{
		sa(head, 1);
		ra(head, 1);
	}
	return ;
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

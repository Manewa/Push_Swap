/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:44 by namalier          #+#    #+#             */
/*   Updated: 2024/03/25 12:54:45 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	count_move_rrr(t_list **search)
{
	(*search)->addr = 0;
	if ((*search)->rr != 0)
		(*search)->addr = (*search)->ra + (*search)->rb - (*search)->rr;
	else if ((*search)->rrr != 0)
		(*search)->addr = (*search)->rra + (*search)->rrb - (*search)->rrr;
	if ((*search)->addr <= (*search)->count_move && (*search)->addr != 0)
		(*search)->count_move = (*search)->addr;
}

void	main_algo(t_list **a)
{
	t_list	*b;
	t_list	*tmp;

	b = NULL;
	if (sorted(a) == 1)
		tmp = *a;
	else
	{
		tmp = *a;
		fill_b(a, &b);
		if (b && b->next && b->next->next)
			count_order(&b);
		else
			count_order_a(a);
		tmp = b;
		while (b)
		{
			b = b->next;
			write(1, "pa\n", 3);
		}
	}
	ft_lstfree(&tmp);
	return ;
}

int	move_for_algo(t_list **a, t_list **b)
{
	if ((*a)->next && (*a)->next->next && (*a)->next->next->next
		&& (*a)->next->next->next->next
		&& (*a)->next->next->next->next->next)
	{
		pb(b, a, 1);
		pb(b, a, 1);
		pb(b, a, 1);
		sort_b_under_five(b);
	}
	else if ((*a)->next && (*a)->next->next && (*a)->next->next->next)
	{
		pb(b, a, 1);
		if ((*a)->next->next->next)
			pb(b, a, 1);
		pass_to_a(a, b);
		return (1);
	}
	else
	{
		sort_a_at_three(a);
		return (1);
	}
	return (0);
}

void	fill_b(t_list **a, t_list **b)
{
	t_list	*pass;
	int		highest;

	if (move_for_algo(a, b) == 1)
		return ;
	while (*a)
	{
		highest = find_highest(b);
		count_a(a);
		count_b(a, b);
		count_moves(a);
		find_pass(a, &pass);
		if (pass->content > highest)
			pass_to_highest(&pass, b);
		pass_to_b(a, b, &pass);
	}
	return ;
}

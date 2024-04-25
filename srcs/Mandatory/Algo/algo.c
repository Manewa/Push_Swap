/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <namalier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:44 by namalier          #+#    #+#             */
/*   Updated: 2024/04/25 17:02:58 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_for_algo(t_list **a, t_list **b)
{
	if ((*a)->next && (*a)->next->next && (*a)->next->next->next
		&& (*a)->next->next->next->next
		&& (*a)->next->next->next->next->next)
	{
		pb(b, a, 1);
		pb(b, a, 1);
		pb(b, a, 1);
		sort_b_at_three(b);
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

void	algo_fill_b(t_list **a, t_list **b)
{
	t_list	*pass;
	int		highest;

	if (prepare_for_algo(a, b) == 1)
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

void	main_algo(t_list **a)
{
	t_list	*b;
	t_list	*tmp;

	b = NULL;
	if (sorted(a) == 1)
		return (ft_lstfree(a));
	else
	{
		tmp = *a;
		algo_fill_b(a, &b);
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
	if (*a)
		ft_lstfree(a);
}

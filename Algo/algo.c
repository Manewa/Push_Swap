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
	if ((*search)->rr <= (*search)->rrr && search)
		(*search)->addr = (*search)->ra + (*search)->rb - (*search)->rr;
	else if ((*search)->rrr < (*search)->rr)
		(*search)->addr = (*search)->rra + (*search)->rrb - (*search)->rrr;
	if ((*search)->addr <= (*search)->count_move)
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
/*		if ((*a)->next && (*a)->next->next)
			pass_to_a(a, &b);
		else
		{
			a_to_lowest(a);
			under_five(a, &b);
		}*/
		if (b && b->next && b->next->next)
			count_order(&b);
		else
			count_order_a(a);
		while (b)
		{
			b = b->next;
			write(1, "pa\n", 3);
		}
	}
//	ft_testlst(a, &b);
	return ;
}

void	fill_b(t_list **a, t_list **b)
{
	t_list	*pass;
	size_t	i;
	int		highest;

	i = 0;
	if ((*a)->next && (*a)->next->next && (*a)->next->next->next
			&& (*a)->next->next->next->next
			&& (*a)->next->next->next->next->next)
	{
		pb(b, a);
		pb(b, a);
		pb(b, a);
		sort_b_under_five(b);
	}
	else if ((*a)->next && (*a)->next->next && (*a)->next->next->next)
	{
		pb(b, a);
		if ((*a)->next->next->next)
			pb(b, a);
		pass_to_a(a, b);
		return ;
	}
	else
	{
		sort_a_at_three(a);
		return ;
	}
//	while ((*a)->next && (*a)->next->next && (*a)->next->next->next)
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
		//	Maintenant il faut :
		// Renvoyer vers a en faisant attention a bien mettre les bons chiffres
		// aux bons endroits par rapport aux 3 de a
		// Implementer rr et rrr
	}
	
	return ;
}


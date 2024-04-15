/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_algo3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:02:43 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:02:45 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	move_to_a(t_list **head_a, t_list **head_b, t_list *tail)
{
	while (*head_b)
	{
		tail = ft_lstlast(*head_a);
		while (*head_b && (*head_b)->content > tail->content)
			pa(head_a, head_b, 1);
		rra(head_a, 1);
		tail = ft_lstlast(*head_a);
		while (*head_b && (*head_b)->content < tail->content
			&& tail->content < (*head_a)->content)
		{
			rra(head_a, 1);
			tail = ft_lstlast(*head_a);
		}
		while (*head_b && (*head_b)->content > tail->content)
			pa(head_a, head_b, 1);
		while (*head_b && (*head_b)->content < tail->content
			&& tail->content < (*head_a)->content)
		{
			rra(head_a, 1);
			tail = ft_lstlast(*head_a);
		}
		while (*head_b)
			pa (head_a, head_b, 1);
	}
}

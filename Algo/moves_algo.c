/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:54:14 by namalier          #+#    #+#             */
/*   Updated: 2024/03/25 12:54:17 by namalier         ###   ########.fr       */
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
	pb (head_b, head_a);
	return ;
}
	

void	pass_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*tail;
	int		lowest_a;
//	int 	i;
	
	sort_a_at_three(head_a);
	lowest_a = (*head_a)->content;
	while (*head_b)
	{
		tail = ft_lstlast(*head_a);
		while ((*head_b) && (*head_b)->content > tail->content)
		{
			if (lowest_all(head_a, head_b) == tail->content
				&& (*head_b)->content == highest_all(head_a, head_b))
				rra(head_a, 1);	
			pa(head_a, head_b);
		}
		if ((*head_b) && tail->content == lowest_all(head_a, head_b))
			rra(head_a, 1);
		while ((*head_b) && (*head_b)->content < tail->content)
		{
			rra(head_a, 1);
			tail = ft_lstlast(*head_a);
			if (lowest_all(head_a, head_b) == tail->content
					&& (*head_b)->content == highest_all(head_a, head_b))
			rra(head_a, 1);	
			if ((*head_a)->content == lowest_a)
			{
				while ((*head_b) && (*head_b)->content < (*head_a)->content)
				{
					if (lowest_all(head_a, head_b) == tail->content
						&& (*head_b)->content == highest_all(head_a, head_b))
						rra(head_a, 1);	
					pa(head_a, head_b);
				}
			}
		}
	}
/*	while (tail->content != find_highest(head_a))
	{
		ra(head_a, 1);
		tail = ft_lstlast(*head_a);
	}*/
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

void	count_order(t_list **head_a)
{
	t_list *tmp_a;
	int 	ra;
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

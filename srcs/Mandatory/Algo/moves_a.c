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

void	pass_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*tail;

	sort_a_at_three(head_a);
	if ((*head_b)->next && (*head_b)->content < (*head_b)->next->content)
		sb(head_b, 1);
	tail = NULL;
	move_to_a(head_a, head_b, tail);
}

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

/*void	under_five_b(t_list **head_a, t_list **head_b)
{
	t_list	*tail;

	sort_b_at_three(head_b);
	while (head_b && (*head_b)->content > find_lowest(head_a))
	{
		tail = ft_lstlast(*head_a);
		while (*head_b && (*head_b)->content > tail->content)
			pa(head_a, head_b, 1);
		if ((*head_b)->content < tail->content)
			rra(head_a, 1);
	}
	while (head_b)
		pa(head_a, head_b, 1);
	return ;
}*/
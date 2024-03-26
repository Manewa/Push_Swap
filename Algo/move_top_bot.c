#include "../push_swap.h"

void	b_to_highest(t_list **head)
{
	int	highest;
	int	i;

	i = 0;
	highest = find_highest(head);
	while ((*head)->content != highest)
		rrb(head, 1);
	if ((*head)->next->content < (*head)->next->next->content)
	{
		sb(head, 1);
		rb(head, 1);
	}
	return ;	
}

void	a_to_lowest(t_list **head)
{
	int	lowest;
	int	i;

	i = 0;
	lowest = find_lowest(head);
	while ((*head)->content != lowest)
		rra(head, 1);
	if ((*head)->next->content > (*head)->next->next->content)
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
	int	highest;
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

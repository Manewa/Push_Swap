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

void	pass_to_b(t_list **head_a, t_list **head_b, t_list **pass)
{
	if ((*pass)->move_up >= (*pass)->move_down)
	{
		while ((*pass)->move_down != 0)
		{
			rra(head_a, 1);
			(*pass)->move_down -= 1;
		}
	}
	else
	{
		while ((*pass)->move_up != 0)
		{
			{
				ra(head_a, 1);
				(*pass)->move_up -= 1;
			}
		}
	}
	position_b(head_b, pass); 
	pb (head_b, head_a);
	return ;
}

void	a_to_lowest(t_list **head)
{
	int	lowest;
	int	i;

	i = 0;
	lowest = find_lowest(head);
	while ((*head)->content != lowest)
		ra(head, 1);
	if ((*head)->next->content > (*head)->next->next->content)
	{
		sa(head, 1);
		ra(head, 1);
	}
	return ;
}	

void	pass_to_a(t_list **head_a, t_list **head_b)
{
	t_list	*one_a;
	t_list	*two_a;
	t_list	*tail;
	
	a_to_lowest(head_a);
	one_a = *head_a;
	two_a = (*head_a)->next;
	while ((*head_b))
	{
		tail = ft_lstlast(*head_a);
		while ((*head_b) && (*head_b)->content > tail->content)
			pa(head_a, head_b);
		while ((*head_b) && (*head_b)->content < ft_lstlast(*head_a)->content &&
				(*head_a)->content != one_a->content)
			rra(head_a, 1);
		while ((*head_b) && (*head_b)->content > (*head_a)->content)
			pa(head_a, head_b);
		while ((*head_b) && (*head_b)->content < ft_lstlast(*head_a)->content &&
				(*head_a)->content != one_a->content)
			rra(head_a, 1);
		while ((*head_b) && (*head_b)->content < (*head_a)->content)
			pa(head_a, head_b);
	}

		/*		rra(head_a, 1);
		if ((*head_b)->next && two_a->content > (*head_b)->content)
			rra(head_a, 1);
		while((*head_b) && (*head_b)->content > two_a->content)
			pa(head_a, head_b);
		if ((*head_b) && !(two_a->next))
			rra(head_a, 1);
		while ((*head_b) && (*head_b)->content > one_a->content)
			pa(head_a, head_b);
		rra(head_a, 1);
		while (*head_b && ((*head_b)->content < tail->content ||
				(*head_b)->content < two_a->content))
			pa(head_a, head_b);
*/	
	

	/*if (tmpb->content > (*head_a)->content)
	{
		if (tail->move_up == 1)
			ra(head_a, 1);
		else
			rra(head_a, 1);
	}
	while (tmpb->next)
	{
		while (tmpb->content > two_a->content && tmpb->content > tail->content)
			pa(head_a, 1);
		if (two->content > tail->content)

	}
*/
/*	t_list	*tmpb;
	t_list	*tail_a;

	tmpb = *head_b;
	tail_a = a_to_highest(head_a);
	if (tmpb->content > (*head_a)->content)
	{
		if (tail_a->move_up == 1)
			ra(head_a, 1);
		else
			rra(head_a, 1);
	}
	while (tmpb->next)
	{
		while (tmpb->content > (*head_a)->content)
			pa(head_a, &tmpb);
		if (tail_a->move_up == 1)
			ra(head_a, 1);
		else
			rra(head_a, 1);
		while(tmpb->next && tmpb->content < (*head_a)->content)
			pa(head_a, &tmpb);
		ra(head_a, 1);

	}
*/	return ;
}

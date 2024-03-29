#include "../push_swap.h"

void	move_rrr(t_list **head_a, t_list **head_b, t_list **pass)
{
	if ((*pass)->rr < (*pass)->rrr)
	{
		while ((*pass)->rr != 0)
		{
			rr(head_a, head_b);
			(*pass)->rr -= 1;
			(*pass)->ra -= 1;
			(*pass)->rb -= 1;
		}
	}
	else if ((*pass)->rrr < (*pass)->rr)
	{
		while ((*pass)->rrr != 0)
		{
			rrr(head_a, head_b);
			(*pass)->rra -= 1;
			(*pass)->rrb -= 1;
			(*pass)->rrr -= 1;
		}
	}
}

long int	lowest_all(t_list **head_a, t_list **head_b)
{
	int	lowesta;
	int lowestb;

	lowesta = find_lowest(head_a);
	lowestb = find_lowest(head_b);
	if (lowesta < lowestb)
		return (lowesta);
	return (-2147483649);
}

long int	highest_all(t_list **head_a, t_list **head_b)
{
	int	highesta;
	int highestb;

	highesta = find_highest(head_a);
	highestb = find_highest(head_b);
	if (highesta < highestb)
		return (highestb);
	return (-2147483649);
}

void	under_five(t_list **head_a, t_list **head_b)
{
	t_list *tail;


	sort_b_under_five(head_b);
	while (head_b && (*head_b)->content > find_lowest(head_a))
	{
		tail = ft_lstlast(*head_a);
		while (*head_b && (*head_b)->content > tail->content)
			pa(head_a, head_b);
		if ((*head_b)->content < tail->content)
			rra(head_a, 1);
	}
	while (head_b)
		pa(head_a, head_b);
//	opti_sorted(head_a);
	return ;
}

void	sort_b_under_five(t_list **head_b)
{
	if ((*head_b)->content == find_lowest(head_b)
			&& (*head_b)->next->content > (*head_b)->next->next->content)
		rb (head_b, 1);
	else if ((*head_b)->content == find_lowest(head_b)
				&& (*head_b)->next->content < (*head_b)->next->next->content)
	{
		sb(head_b, 1);
		rrb(head_b, 1);
	}
	else if ((*head_b)->next->content == find_lowest(head_b)
			&& (*head_b)->content > (*head_b)->next->next->content)
	{
		sb(head_b, 1);
		rb(head_b, 1);
	}
	else if ((*head_b)->next->content == find_lowest(head_b)
			&& (*head_b)->content < (*head_b)->next->next->content)
		rrb(head_b, 1);
	else if ((*head_b)->next->next->content == find_lowest(head_b)
			&& (*head_b)->content < (*head_b)->next->content)
			sb(head_b, 1);
	return ;
}

/*void	opti_sorted(t_list **head_a)
{
	t_list	*search_a;

	search_a = *head_a;
	while (
}*/

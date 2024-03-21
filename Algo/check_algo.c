#include "../push_swap.h"

int	sorted(t_list **a)
{
	t_list	*move;

	move = *a;
	while (move->next)
	{
		if (move->content > move->next->content)
			return (0);
		move = move->next;
	}
	return (1);
}

int	find_lowest(t_list **head_a)
{
	int		lowest;
	t_list	*tmpa;

	tmpa = *head_a;
	lowest = tmpa->content;
	while (tmpa->next)
	{
		tmpa = tmpa->next;
		if (lowest > tmpa->content)
			lowest = tmpa->content;
	}
	return (lowest);
}

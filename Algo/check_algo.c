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

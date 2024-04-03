#include "../push_swap.h"

void	count_order_a(t_list **head_a)
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
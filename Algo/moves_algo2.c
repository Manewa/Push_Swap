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

#include "push_swap.h"


void	count_r(t_list **search, int countra, int countrb)
{
	if ((*search)->ra <= (*search)->rra && (*search)->rb <= (*search)->rrb)
	{
		countra = (*search)->ra;
		countrb = (*search)->rb;
		while (countra != 0 && countrb != 0)
		{
			countra -= 1;
			countrb -= 1;
			(*search)->rr += 1;
		}
	}
}

void	count_rrr(t_list **search)
{
	int		countra;
	int		countrb;

	countra = 0;
	countrb = 0;
	(*search)->rr = 0;
	(*search)->rrr = 0;
	if ((*search)->ra <= (*search)->rra && (*search)->rb <= (*search)->rrb)
		count_r(search, countra, countrb);
	else if ((*search)->rra <= (*search)->ra && (*search)->rrb <= (*search)->rb)
	{
		countra = (*search)->rra;
		countrb = (*search)->rrb;
		while (countra != 0 && countrb != 0)
		{
			countra -= 1;
			countrb -= 1;
			(*search)->rrr += 1;
		}
	}
}

void	count_move_rrr(t_list **search)
{
	(*search)->addr = 0;
	if ((*search)->rr != 0)
		(*search)->addr = (*search)->ra + (*search)->rb - (*search)->rr;
	else if ((*search)->rrr != 0)
		(*search)->addr = (*search)->rra + (*search)->rrb - (*search)->rrr;
	if ((*search)->addr <= (*search)->count_move && (*search)->addr != 0)
		(*search)->count_move = (*search)->addr;
}

void	move_rrr(t_list **head_a, t_list **head_b, t_list **pass)
{
	while ((*pass)->rr != 0)
	{
		rr(head_a, head_b, 1);
		(*pass)->rr -= 1;
		(*pass)->ra -= 1;
		(*pass)->rb -= 1;
	}
	while ((*pass)->rrr != 0)
	{
		rrr(head_a, head_b, 1);
		(*pass)->rra -= 1;
		(*pass)->rrb -= 1;
		(*pass)->rrr -= 1;
	}
}
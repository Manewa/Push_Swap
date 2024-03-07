#include "../push_swap.h"

t_list	**main_algo(t_list **a)
{
	t_list	*b;
	t_list	*tmp;
	
	b = NULL;
	if (sorted(a) == 1)
		tmp = *a;
	else
	{
		tmp = *a;
		fill_b(a, &b);
	}
	ft_testlst(a, &b);
	return (a);
}

void	fill_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	size_t	i;

	tmp = *a;
	i = 0;
	while (i < 2 && *a)
	{
		*a = (*a)->next;
		i++;
	}
	if (i < 2)
		return ;
	*a = tmp;
	while ((*a)->next->next->next)
		pb(b, a);
	
	return ;
}

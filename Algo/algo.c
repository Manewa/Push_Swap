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
	t_list	*pass;
	size_t	i;
	int		highest;

	i = 0;
	if ((*a)->next && (*a)->next->next && (*a)->next->next)
	{
		pb(b, a);
		pb(b, a);
		pb(b, a);
	}
	else
	{
		ra(a, 1);
		return ;
	}
	while ((*a)->next && (*a)->next->next && (*a)->next->next->next)
	{
		highest = find_highest(b);
		count_a(a);
		count_b(a, b);
		find_pass(a, &pass);
		if (pass->content > highest)
			pass_to_highest(&pass, b);
		pass_to_b(a, b, &pass);
//		ft_testlst(a, b);
		//TROP BIEN ! La stack B est officiellement TRIEEEEEEEEEEEEEEE
		//BRAVOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
		//	Maintenant il faut :
		// Renvoyer vers a en faisant attention a bien mettre les bons chiffres
		// aux bons endroits par rapport aux 3 de a
		// Implementer rr et rrr
	}
	return ;
}


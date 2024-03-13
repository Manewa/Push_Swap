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

	i = 0;
	pb(b, a);
	pb(b, a);
	tmp = *a;
	while ((*a)->next && (*a)->next->next && (*a)->next->next->next)
	{
		count_a(a);
		count_b(a, b);
		// 		Segfault normal -> Boucle infinie juste au dessus
		// 		puisque pas de mouvement demande encore.
		//Verifier si le count_move fonctionne bien puis :
		// 1) Trouver le plus petit count_move
		// 2) Coder le nouvement simple pas opti de ra et rb puis finir sur un sa
		// 3) Regarder si ca fonctionne
		// 4) Implementer rr et rrr
	}
	return ;
}

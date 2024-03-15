#include "../push_swap.h"

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
	pb (head_b, head_a);
//	ft_testlst(head_a, head_b);
	return ;
//	Ici, la fonction ne passe que depuis la stack a et ne bouge pas encore la stack b
//	il faut donc chercher a optimiser la stack b en meme temps (Si ra et rb alors
//	faire des rr, idem pour rrr, jusqu'a ce que l'un soit = 0.
//	Multiples fonctions pour faire tout ca a cause des 25 lignes.
}

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

	i = 0;
	if ((*a)->next && (*a)->next->next)
	{
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
		count_a(a);
		count_b(a, b);
		find_pass(a, &pass);
		pass_to_b(a, b, &pass);
		
		// 		Segfault normal -> Boucle infinie juste au dessus
		// 		puisque pas de mouvement demande encore.
		//Verifier si le count_move fonctionne bien puis :
		// !! DONE !! 1) Trouver le plus petit count_move
		// 2) Coder le nouvement simple pas opti de ra et rb puis finir sur un sa
		// 3) Regarder si ca fonctionne
		// 4) Implementer rr et rrr
	}
	return ;
}

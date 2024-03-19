#include "../push_swap.h"

void	position_b(t_list **head_b, t_list **pass)
{
	if ((*pass)->rb >= (*pass)->rrb)
	{
		printf("pouet\n");
		while ((*pass)->rrb != 0)
		{
			printf("pouet2\n");
			rrb(head_b, 1);
			(*pass)->rrb -= 1;
		}
	}
	else
	{
		printf("pouet3\n");
		while ((*pass)->rb != 0)
		{
			printf("pouet4\n");
			rb(head_b, 1);
			(*pass)->rb -= 1;
		}
	}
	return ;
}

void	pass_to_highest(t_list **pass, t_list **b)
{
	t_list	*tmpb;

	tmpb = *b;
	(*pass)->rb = 0;
	(*pass)->rrb = 0;
	while (tmpb->next && tmpb->content > tmpb->next->content)
	{
		(*pass)->rb += 1;
		tmpb = tmpb->next;
	}
	if (tmpb->next)
		(*pass)->rb += 1;
	while (tmpb->next)
	{
		(*pass)->rrb += 1;
		tmpb = tmpb->next;
	}
	return ;
}

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
	position_b(head_b, pass); 
	pb (head_b, head_a);
	ft_testlst(head_a, head_b);
	return ;
//	Ici, la fonction ne passe que depuis la stack a et ne bouge pas encore la stack b
//	il faut donc chercher a optimiser la stack b en meme temps (Si ra et rb alors
//	faire des rr, idem pour rrr, jusqu'a ce que l'un soit = 0.
//	Multiples fonctions pour faire tout ca a cause des 25 lignes.
}



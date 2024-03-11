#include "../push_swap.h"

void	count_move(t_list **head)
{
	t_list	*search;
	t_list	*tmp;

	search = *head;
	search->move_down = -1;
	while (search->move_down != 0)
	{
		if (search->move_down >= 0)
				search = search->next;
		tmp = *head;
		search->move_up = 0;
		search->move_down = 0;
		while (tmp->content != search->content)
		{
			search->move_up = search->move_up + 1;
			tmp = tmp->next;
		}
		while (tmp->next)
		{
			search->move_down = search->move_down + 1;
			tmp = tmp->next;
		}
		printf("Up : %d || Down %d\n", search->move_up, search->move_down);
		//ajouter fonction pour compter les mouvements pour le mettre a la
		//bonne place en stack b
	}
	return ;
}

void	top_or_bot(t_list **head_a, t_list **head_b)
{
	t_list	*tail_b;

	tail_b = ft_lstlast(*head_b);
	if (
		//Je sais pas encore vraiment quoi en faire faut revoir l'algo la
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
	t_list	*tmp_a;
	t_list	*tmp_b;
	size_t	i;

	tmp = *a;
	i = 0;
	pb(b, a);
	pb(b, a);
	count_move(a);
	while (tmp->next && tmp->next->next && tmp->next->next->next)
	{
		if (tmp->content < tmp->next->content)
			tmp = tmp->next;
		else
		{
			top_or_bot(a);
			//Go prendre une feuille et tout noter parce que je crois qu'on 
			//opti l'algo encore plus.
	}
/*	while (i < 2 && *a)
	{
		*a = (*a)->next;
		i++;
	}
	if (i < 2)
		return ;
	*a = tmp;
	while ((*a)->next->next->next)
		pb(b, a);
	return ;*/
}

#include "../push_swap.h"

void	count_a(t_list **head)
{
	t_list	*search;
	t_list	*tmp;

	search = *head;
	search->move_down = -1;
	while (search->move_down != 1)
	{
		if (search->move_down >= 0)
				search = search->next;
		tmp = *head;
		search->move_up = 0;
		search->move_down = 1;
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
		//ajouter fonction pour compter les mouvements pour le mettre a la
		//bonne place en stack b
	}
}


void	count_moves(t_list **head_a)
{
	t_list	*search;
	
	search = *head_a;
	search->count_move = -1;
	while (search->next)
	{
		if (search->count_move >= 0)
			search = search->next;
		if (search->rb < search->rrb)
		{
			if (search->move_up < search->move_down)
				search->count_move = search->rb + search->move_up;
			else
				search->count_move = search->rb + search->move_down;
		}
		else
		{
			if (search->move_up < search->move_down)
				search->count_move = search->rrb + search->move_up;
			else
				search->count_move = search->rrb + search->move_down;	
		}
		printf("Count_moves = %d\n", search->count_move);
	}
}

void	count_b(t_list **head_a, t_list **head_b)
{
	t_list	*search_a;
	t_list	*search_b;

	search_a = *head_a;
	search_a->rrb = -1;
	while (search_a->next)
	{
		if (search_a->rrb >= 0)
			search_a = search_a->next;
		search_a->rb = 0;
		search_a->rrb = 1;
		search_b = *head_b;
		while (search_a->content < search_b->content && search_b->next)
		{
			search_a->rb += 1;
			search_b = search_b->next;
		}
		while (search_b->next)
		{
			search_a->rrb += 1;
			search_b = search_b->next;
		}
	}
	count_moves(head_a);
}

void	find_pass(t_list **head_a, t_list **pass)
{
	t_list	*tmp;

	pass = head_a;
	tmp = *head_a;
	while (tmp->next)
	{
		if ((*pass)->count_move > tmp->count_move)
			*pass = tmp;
		tmp = tmp->next;
	}
	if ((*pass)->count_move > tmp->count_move)
		*pass = tmp;
	return ;
}

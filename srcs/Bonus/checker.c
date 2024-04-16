/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:41:17 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:46:05 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"



int	moves_algo(t_list **head_a, t_list **head_b, char *m)
{
	if (m[0] == 's' && m[1] == 'a' && m[2] == '\0')
		sa (head_a, 0);
	else if (m[0] == 's' && m[1] == 'b' && m[2] == '\0')
		sb (head_b, 0);
	else if (m[0] == 's' && m[1] == 's' && m[2] == '\0')
		ss(head_a, head_b, 0);
	else if (m[0] == 'p' && m[1] == 'a' && m[2] == '\0')
		pa (head_a, head_b, 0);
	else if (m[0] == 'p' && m[1] == 'b' && m[2] == '\0')
		pb (head_b, head_a, 0);
	else if (m[0] == 'r' && m[1] == 'a' && m[2] == '\0')
		ra (head_a, 0);
	else if (m[0] == 'r' && m[1] == 'b' && m[2] == '\0')
		rb (head_b, 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == '\0')
		rr (head_a, head_b, 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == 'a' && m[3] == '\0')
		rra (head_a, 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == 'b' && m[3] == '\0')
		rrb (head_b, 0);
	else if (m[0] == 'r' && m[1] == 'r' && m[2] == 'r' && m[3] == '\0')
		rrr (head_a, head_b, 0);
	else
		return (0);
	return (1);
}

int	checker_algo(t_list **head_a, t_list **head_b, char **moves, char *move)
{
	size_t	i;
	t_list	*tmpa;

	i = 0;
	while (moves[i])
	{
		if (moves_algo(head_a, head_b, moves[i]) == 1)
			i++;
		else
		{
			ft_lstfree(head_a);
			ft_lstfree(head_b);
			ft_free(moves, move, '\n');
			free(move);
			ft_exit();
		}
	}
	tmpa = *head_a;
	while (tmpa && tmpa->next && tmpa->content < tmpa->next->content)
		tmpa = tmpa->next;
	if (tmpa && !(tmpa->next) && !(*head_b))
		return (1);
	else
		return (0);
}

void	lstcreate_bonus(t_list **a, long int *split)
{
	int	i;

	i = 1;
	while (split[0] >= i)
	{
		if (i == 1)
		{
			(*a)->content = split[1];
			i++;
		}
		else
		{
			if ((ft_lstadd_back(a, ft_lstnew(split[i]))) == 0)
				i++;
			else
			{
				ft_lstfree(a);
				free(split);
				exit (1);
			}
		}
	}
	return (free(split));
}

int	checker(char **moves, char *move, long int *split)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(1);
	b = NULL;
	if (!a)
	{
		free(split);
		ft_free(moves, move, '\n');
		ft_exit();
	}
	lstcreate_bonus(&a, split);
	if (checker_algo(&a, &b, moves, move) == 1)
	{
		ft_lstfree(&a);
		ft_free(moves, move, '\n');
		return (1);
	}
	else
	{
		ft_lstfree(&a);
		ft_lstfree(&b);
		ft_free(moves, move, '\n');
		return (0);
	}
}

int	main(int argc, char **argv)
{
	char		*move;
	char		**moves;
	long int	*split;

	if (argc < 2)
		ft_exit();
	ft_check_errors(argv);
	split = ft_parse_bonus(argc, argv);
	if (split == NULL)
		ft_exit();
	if (parsing_bonus(&move, &moves, split) == 1)
	{
		free (split);
		ft_exit();
	}
	if (checker(moves, move, split) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free(move);
	return (0);
}

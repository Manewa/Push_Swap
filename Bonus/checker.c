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

char	*join_move(void)
{
	char	*buffer;
	char	*str;

	str = ft_strdup("\0");
	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer)
			return (str);
		str = ft_strjoin(str, buffer, 0);
		if (!str)
		{
			free(str);
			ft_exit();
		}
	}
}

int	moves_algo(t_list **head_a, t_list **head_b, char *moves)
{
	if (moves == "sa\n")
		sa (head_a, 0);
	else if (moves == "sb\n")
		sb (head_b, 0);
	else if (moves == "ss\n")
		ss(head_a, head_b, 0);
	else if (moves == "pa\n")
		pa (head_a, head_b, 0);
	else if (moves == "pb\n")
		pb (head_b, head_a, 0);
	else if (moves == "ra\n")
		ra (head_a, 0);
	else if (moves == "rb\n")
		rb (head_b, 0);
	else if (moves == "rr\n")
		rr (head_a, head_b, 0);
	else if (moves == "rra\n")
		rra (head_a, 0);
	else if (moves == "rrb\n")
		rrb (head_b, 0);
	else if (moves == "rrr\n")
		rrr (head_a, head_b, 0);
	else
		return (0);
	return (1);
}

int	checker_algo(t_list **head_a, t_list **head_b, char **moves)
{
	size_t	i;
	t_list	*tmpa;

	i = 0;
	tmpa = *head_a;
	while (moves[i])
	{
		if (moves_algo(head_a, head_b, moves[i]) == 1)
			i++;
		else
		{
			ft_lstfree(head_a);
			ft_lstfree(head_b);
			free(moves);
			ft_exit();
		}
	}
	while (tmpa && tmpa->next && tmpa->content < tmpa->next->content)
	{
		tmpa = tmpa->next;
	}
	if (!(tmpa->next))
		return (1);
	else
		return (0);
}

int	checker(char **moves, int *split)
{
	t_list	*a;
	t_list	*b;

	a = ft_lstnew(1);
	b = NULL;
	if (!a)
	{
		free(split);
		ft_free(moves);
		ft_exit();
	}
	lstcreate(&a, split);
	if (checker_algo(&a, &b, moves) == 1)
	{
		ft_lstfree(&a);
		free(moves);
		return (1);
	}
	else
	{
		ft_lstfree(&a);
		ft_lstfree(&b);
		free(moves);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	char	*move;
	char	**moves;
	int		*split;

	if (ac < 2)
		ft_exit();
	ft_check_errors(argv);
	move = join_move();
	moves = ft_split(move, ' ');
	split = ft_parse(argc, argv);
	if (!moves || split == NULL)
	{
		free(moves);
		ft_exit();
	}
	if (ft_check_double(split) == 1)
	{
		free(moves);
		ft_free(split, move, ' ');
		ft_exit();
	}
	if (checker(moves, split) == 1)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	return (0);
}

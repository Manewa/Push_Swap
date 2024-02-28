/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:45:21 by namalier          #+#    #+#             */
/*   Updated: 2024/02/21 11:48:43 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstcreate(t_list **a, int *split)
{
	int i;

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
			ft_lstadd_back(a, ft_lstnew(split[i]));
			i++;
	
		}
	}
	return (free(split));
}

int	*ft_parse(int argc, char **argv)
{
	size_t i;
	char *str;
	int *num;
	char **split;

	i = 1;
	str = "\0";
	while (i < (size_t)argc)
	{
		str = ft_strjoin(str, argv[i], i);
		if (!str)
			exit (1);
		i++;
	}
	split = ft_split(str, ' ');
	if (!split)
		return (free(str), NULL);
	i = 0;
	while (split[i])
		i++;
	num = malloc((i + 1) * sizeof(int));
	if (!num)
		return (ft_free(split, str, ' '), free(str), NULL);
	num[0] = i;
	while (i > 0)
	{
		num[i] = ft_atoi(split[i - 1]);
		i--;
	}
	return (ft_free(split, str, ' '), free(str), num);
}

int main (int argc, char **argv)
{
	int *split;
	t_list *a;
//	t_list *b;

//	split[0][0] = 0;
	if (argc <= 1)
		exit (1);

	ft_check_errors(argv);
	a = ft_lstnew(1);
	split = ft_parse(argc, argv);
	if (ft_check_double(split) == 1)
	{
		ft_lstfree(&a);
		ft_exit();
	}
	lstcreate(&a, split);
	while (a->next)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("%d\n", a->content);
	ft_lstfree(&a);
	return (0);
}

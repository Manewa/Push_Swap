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
#include <stddef.h>
#include<stdio.h>
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
	return ;
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
			return (NULL);
		i++;
	}
	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
		i++;
	num = malloc((i + 1) * sizeof(int));
	if (!num)
		return (0);
	num[0] = i;
	while (i > 0)
	{
		num[i] = ft_atoi(split[i - 1]);
		i--;
	}
	return (ft_free(split, str, ' '), num);
}

int main (int argc, char **argv)
{
	int *split;
	t_list *a;
//	t_list *b;

//	split[0][0] = 0;
	a = ft_lstnew(1);
	split = ft_parse(argc, argv);
	lstcreate(&a, split);
	while (a->next)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
	printf("%d\n", a->content);
	return (0);
}

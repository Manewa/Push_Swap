/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:45:21 by namalier          #+#    #+#             */
/*   Updated: 2024/04/19 15:37:21 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_parse_add(char **split, char *str, long int *num)
{
	size_t	i;

	i = 0;
	while (split[i])
		i++;
	num = malloc((i + 1) * sizeof(long int));
	if (!num)
		return (ft_free(split, str, ' '), free(str), NULL);
	num[0] = i;
	while (i > 0)
	{
		num[i] = ft_atoi(split[i - 1]);
		if (num[i] < -2147483648 || num [i] > 2147483647)
			return (free(num), ft_free(split, str, ' '), free(str), NULL);
		i--;
	}
	return (ft_free(split, str, ' '), free(str), num);
}

long int	*ft_parse(int argc, char **argv)
{
	size_t		i;
	char		*str;
	long int	*num;
	char		**split;

	i = 1;
	str = "\0";
	num = NULL;
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
	num = ft_parse_add(split, str, num);
	return (num);
}

void	lstcreate(t_list **a, long int *split)
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

int	main(int argc, char **argv)
{
	long int	*split;
	t_list		*a;

	if (argc <= 1)
		exit (1);
	ft_check_errors(argv);
	split = ft_parse(argc, argv);
	if (split == NULL)
		ft_exit();
	if (ft_check_double(split) == 1)
	{
		free(split);
		ft_exit();
	}
	a = ft_lstnew(1);
	if (!a)
		return (free(split), 0);
	lstcreate(&a, split);
	main_algo(&a);
	return (0);
}

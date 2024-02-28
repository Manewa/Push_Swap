/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:42:52 by namalier          #+#    #+#             */
/*   Updated: 2024/02/27 16:42:54 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit()
{
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_num(char **str)
{
	size_t	i;
	size_t	j;
	
	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == 0)
			ft_exit();
		while (str[i][j])
		{
			if ((str[i][j] <= '9' && str[i][j] >= '0') || str[i][j] == 32 ||
				str[i][j] == '-' || str[i][j] == '+')
					j++;
			else
				ft_exit();
		}
		i++;
	}
}

void	ft_sign(char **str)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && (str[i][j] != '-' || str[i][j] != '+'))
		{
			if (str[i][j] == '-' || str[i][j] == '+')\
			{
				if ((j > 0 && str[i][j - 1] == ' ' && str[i][j + 1] >= '0' &&
					str[i][j + 1] <= '9') || (j == 0 && str[i][j + 1] >= '0' &&
					str[i][j + 1] <= '9'))
					j++;
				else
					ft_exit();
			}
			j++;
		}
		i++;
	}
	return ;
}

int	ft_check_double(int *num)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (num[0] > i)
	{
		j = i + 1;
		while (num[0] >= j && num[i] != num[j])
			j++;
		if (num[0] >= j && num[i] == num[j])
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_errors(char **str)
{
	ft_num(str);
	ft_sign(str);
	return ;
}

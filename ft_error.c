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

void	ft_error(char **str)
{
	size_t	i;
	size_t	j;
	
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if ((str[i][j] <= '9' && str[i][j] >= '0') || str[i][j] == 32 ||
				((str[i][j] == '-' || str[i][j] == '+') && (str[i][j + 1] > '0'
				 || str[i][j + 1] < '9')))
					j++;
			else
			{
				write(2, "Error\n", 6);
				exit (1);
			}
		}
		i++;
	}
}
/*
void	ft_check_double(char **str)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	
}*/

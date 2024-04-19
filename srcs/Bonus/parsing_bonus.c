/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:55:04 by namalier          #+#    #+#             */
/*   Updated: 2024/04/19 16:55:22 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_bonus(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s2 || !s1)
		return (NULL);
	if (s2[0] == '\n')
		return (free (s1), NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	free (s1);
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

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
		str = ft_strjoin_bonus(str, buffer);
		free (buffer);
		if (!str)
		{
			free(str);
			return (NULL);
		}
	}
}

int	parsing_bonus(char **move, char ***moves, long int *split)
{
	if (ft_check_double(split) == 1)
	{
		free(split);
		ft_exit();
	}
	*move = join_move();
	if (*move == NULL)
		return (1);
	*moves = ft_split(*move, '\n');
	if (!(*moves))
	{
		free(*move);
		ft_exit();
	}
	return (0);
}

long int	*ft_parse_add_bonus(char **split, char *str, long int *num)
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

long int	*ft_parse_bonus(int argc, char **argv)
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
	num = ft_parse_add_bonus(split, str, num);
	return (num);
}

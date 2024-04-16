/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:09:19 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 19:40:59 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long int	ft_atoi2(const char *str, int i, int j, int sign)
{
	long int	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((i - j == 10 && ((str[i] >= '8' && sign > 0) || (str[i] >= '9'
						&& sign < 0))) || i - j >= 11)
			return (21474834888);
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num);
}

long int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	j = i;
	num = ft_atoi2(str, i, j, sign);
	return (num * sign);
}

char	*ft_strjoin(char *s1, char const *s2, size_t entry)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s2 || (!s1 && entry > 1))
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	if (entry > 1)
		free (s1);
	while (s2[j])
		str[i++] = s2[j++];
	str[i++] = ' ';
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	str = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while ((int)j < ft_count_word(s, c))
	{
		if (s[i] == c)
			return (ft_free(str, s, c), NULL);
		str[j] = ft_cpy_str(str[j], s, &i, c);
		if (!str[j])
			return (ft_free(str, s, c), NULL);
		while (s[i] == c)
			i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

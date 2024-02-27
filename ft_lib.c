/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:09:19 by namalier          #+#    #+#             */
/*   Updated: 2024/02/21 11:09:20 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	return (num * sign);
}

char	*ft_strjoin(char *s1, char const *s2, size_t entry)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	if (!s2)
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
		while (s[i] == c)
			i++;
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

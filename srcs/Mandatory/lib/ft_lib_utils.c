/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namalier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:48:41 by namalier          #+#    #+#             */
/*   Updated: 2024/04/11 16:19:31 by namalier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_count_word(char const *s, char c)
{
	int		count_word;
	size_t	i;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count_word++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count_word);
}

char	*ft_cpy_str(char *str, char const *s, size_t *i, char c)
{
	size_t	j;
	size_t	ib;

	j = 0;
	ib = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	str = malloc((*i - ib + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (ib < *i)
	{
		str[j] = s[ib];
		j++;
		ib++;
	}
	str[j] = '\0';
	return (str);
}

void	ft_free(char **str, char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = ft_count_word(s, c);
	while (i <= count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	str = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

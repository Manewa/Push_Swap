#include <stddef.h>
#include <stdlib.h>
#include "push_swap.h"
#include<stdio.h>

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
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	return ;
}

/*void	ft_freeint(int *num)
{
	int	i;

	i = num[0];
	while (i >= 0)
	{
		free (num[i]);
		i--;
	}
	return ;
}*/

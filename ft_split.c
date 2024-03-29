/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpilo <nkarpilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:07:08 by nkarpilo          #+#    #+#             */
/*   Updated: 2024/02/09 14:28:27 by nkarpilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	free_split(char **split, int word)
{
	int	i;

	i = 0;
	if (!split[word])
	{
		while (i < word)
		{
			free(split[i]);
			i++;
		}
		free(split);
		return (1);
	}
	return (0);
}

static void	write_word(char *dest, char *from, char c)
{
	int		i;

	i = 0;
	while (from[i] != c && from[i] != '\0')
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	count_words(char *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
}

static int	write_split(char **split, char *str, char c)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			j = 0;
			while (str[i + j] != c && str[i + j] != '\0')
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (free_split(split, word) == 1)
				return (1);
			write_word(split[word], str + i, c);
			i += j;
			word++;
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**res;
	int		words;

	words = count_words((char *)s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == 0)
		return (0);
	res[words] = 0;
	if (write_split(res, (char *)s, c) == 1)
		return (0);
	return (res);
}

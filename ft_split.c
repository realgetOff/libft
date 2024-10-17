/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 04:54:45 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/17 00:31:03 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_alloc_word(char const *s, char c, int *i)
{
	int		word_len;
	int		j;
	char	*word;

	word_len = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i + word_len] && s[*i + word_len] != c)
		word_len++;
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < word_len)
	{
		word[j] = s[*i + j];
		j++;
	}
	word[j] = '\0';
	*i += word_len;
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **s2, int num_words)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (word < num_words)
	{
		s2[word] = ft_alloc_word(s, c, &i);
		if (!s2[word])
		{
			free_split(s2);
			return (0);
		}
		word++;
	}
	s2[word] = 0;
	return (s2);
}

char	**ft_split(char const *s, char c)
{
	char			**s2;
	unsigned int	num_words;

	if (!s)
		return (0);
	num_words = ft_count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!s2)
		return (0);
	if (!ft_split_words(s, c, s2, num_words))
		return (0);
	return (s2);
}

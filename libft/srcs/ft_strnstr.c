/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 06:26:22 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/10 01:02:06 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s2[j] && (i + j) < len && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		++i;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:25:12 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/12 04:57:44 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	const char	*end;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	end = s1 + ft_strlen(s1);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	while (end > s1 && ft_strchr(set, *(end - 1)))
		end--;
	len = end - s1;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len);
	result[len] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:34:38 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/17 00:33:01 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == '\0')
		return (0);
	while (s1[a] == s2[a] && s1[a] && s2[a] && (a < (n - 1)))
		++a;
	return (((unsigned char)s1[a]) - ((unsigned char)s2[a]));
}

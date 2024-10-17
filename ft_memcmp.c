/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:11:50 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/10 23:40:32 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				a;
	const unsigned char	*ptr1 = (const void *)s1;
	const unsigned char	*ptr2 = (const void *)s2;

	a = 0;
	if (n == '\0')
		return (0);
	while (ptr1[a] == ptr2[a] && (a < (n - 1)))
		++a;
	return (((unsigned char)ptr1[a]) - ((unsigned char)ptr2[a]));
}

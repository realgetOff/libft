/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 03:27:35 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/09 05:48:01 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		a;
	char	*ctrlv;

	a = 0;
	while (s[a])
		a++;
	ctrlv = (char *)malloc((a + 1) * (sizeof(char)));
	if (!ctrlv)
		return (NULL);
	a = 0;
	while (s[a])
	{
		ctrlv[a] = s[a];
		a++;
	}
	ctrlv[a] = '\0';
	return (ctrlv);
}

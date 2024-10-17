/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 03:28:16 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/10 23:58:32 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	a;
	int	res;
	int	pm;

	a = 0;
	res = 0;
	pm = 1;
	while ((nptr[a] >= 9 && nptr[a] <= 13) || (nptr[a] == 32))
		++a;
	if (nptr[a] == '+' || nptr[a] == '-')
	{
		if (nptr[a] == '-')
			pm = -pm;
		++a;
	}
	while (nptr[a] >= '0' && nptr[a] <= '9')
	{
		res = res * 10 + (nptr[a] - '0');
		++a;
	}
	return (pm * res);
}

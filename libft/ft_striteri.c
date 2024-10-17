/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:50:44 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/17 00:32:28 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	striteri_rec(char *s, void (*f)(unsigned int, char *),
		unsigned int i)
{
	if (s[i])
	{
		f(i, &s[i]);
		striteri_rec(s, f, i + 1);
	}
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	if (s && f)
		striteri_rec(s, f, 0);
}

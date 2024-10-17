/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mforest- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:58:50 by mforest-          #+#    #+#             */
/*   Updated: 2024/10/17 03:36:40 by mforest-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_and_return(t_list **head, void *content, void (*del)(void *))
{
	del(content);
	ft_lstclear(head, del);
}

static t_list	*create_node(t_list **head, void *(*f)(void *), t_list *lst,
		void (*del)(void *))
{
	void	*content;
	t_list	*tmp;

	content = f(lst->content);
	if (!content)
	{
		clear_and_return(head, content, del);
		return (NULL);
	}
	tmp = ft_lstnew(content);
	if (!tmp)
	{
		clear_and_return(head, content, del);
		return (NULL);
	}
	ft_lstadd_back(head, tmp);
	return (tmp);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!create_node(&head, f, lst, del))
			return (NULL);
		lst = lst->next;
	}
	return (head);
}

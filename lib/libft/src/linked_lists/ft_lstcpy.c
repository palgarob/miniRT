/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:55:43 by pepaloma          #+#    #+#             */
/*   Updated: 2024/01/13 14:56:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcpy(t_list *lst, void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_list_node0;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(lst->content);
	if (!new_list)
		return (NULL);
	new_list_node0 = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(lst->content);
		if (!new_list->next)
		{
			ft_lstclear(&new_list_node0, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (new_list_node0);
}

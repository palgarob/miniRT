/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:42:29 by pedropalomare     #+#    #+#             */
/*   Updated: 2024/04/27 23:36:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*prev;

	if (!*lst)
		return ;
	aux = (*lst)->next;
	ft_lstdelone(*lst, del);
	if (aux)
	{
		while (aux->next)
		{
			prev = aux->next;
			ft_lstdelone(aux, del);
			aux = prev;
		}
		ft_lstdelone(aux, del);
	}
	*lst = NULL;
}

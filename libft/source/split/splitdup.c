/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitdup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 20:22:30 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:11:46 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**splitdup(char **src)
{
	char	**dup;
	size_t	len;
	char	**aux;

	len = splitlen(src);
	dup = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	aux = dup;
	while (*src)
	{
		*dup = ft_strdup(*src);
		if (!*dup)
			return (NULL);
		src++;
		dup++;
	}
	*dup = NULL;
	return (aux);
}

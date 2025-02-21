/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:24:08 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:38:43 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
			size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize < ft_strlen(dst))
	{
		j = 0;
		i = ft_strlen(src) + dstsize;
	}
	else
	{
		j = dstsize - ft_strlen(dst);
		i = ft_strlen(src) + ft_strlen(dst);
	}
	while (*dst)
		dst++;
	ft_strlcpy(dst, src, j);
	return (i);
}

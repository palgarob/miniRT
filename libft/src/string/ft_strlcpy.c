/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:25:39 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:39:00 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src,
			size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = dstsize;
	i = ft_strlen(src);
	if (n)
		n--;
	while (n-- && *src)
	{
		*(dst++) = *(src++);
	}
	if (dstsize)
		*dst = 0;
	return (i);
}

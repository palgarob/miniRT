/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:28:14 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:37:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dest > sorc)
	{
		while (len-- > 0)
		{
			dest[len] = sorc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

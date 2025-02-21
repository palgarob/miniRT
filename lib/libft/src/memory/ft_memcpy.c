/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:54 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:37:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux;

	if (!dst && !src)
		return (NULL);
	aux = dst;
	while (n > 0)
	{
		ft_memset(aux, *(unsigned char *)src, 1);
		aux++;
		src++;
		n--;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:42:09 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:39:44 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	c = (char)c;
	len = ft_strlen(s);
	if (!len && c)
		return (NULL);
	if (!c)
		return ((char *)&s[len]);
	while (--len)
		if (s[len] == c)
			return ((char *)&s[len]);
	if (s[len] == c)
		return ((char *)&s[len]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:26:28 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:39:54 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	found(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set)
{
	char	*end;

	end = s1 + ft_strlen(s1);
	while (found(*s1, set))
	{
		s1++;
	}
	while (found(*(end - 1), set))
	{
		end--;
	}
	if (end < s1)
		s1 = end;
	return (ft_substr(s1, 0, end - s1));
}

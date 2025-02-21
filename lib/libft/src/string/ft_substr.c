/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:16:42 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/27 23:40:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;

	if (*s)
	{
		if (start > ft_strlen(s))
			start = ft_strlen(s);
		s = s + start;
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ss = (char *)malloc(sizeof(char) * (len + 1));
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, s, len + 1);
	return (ss);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:38:23 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:12:50 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = (char *)malloc(ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}

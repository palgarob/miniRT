/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:44:59 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:12:14 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	store_s(char **ss_array, char *s, char c, size_t len)
{
	int		i;

	i = 0;
	*ss_array = (char *)malloc(sizeof(char) * (len + 1));
	if (!*ss_array)
		return (0);
	while (*s != c && *s)
	{
		ss_array[0][i++] = *(s++);
	}
	ss_array[0][i] = 0;
	return (1);
}

static size_t	count_s(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

static int	store_ss(char **ss_array, char *s, char c)
{
	size_t	len;
	int		free_counter;

	free_counter = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = count_s(s, c);
			if (!store_s(ss_array, s, c, len))
			{
				while (free_counter--)
					free(*--ss_array);
				return (0);
			}
			free_counter++;
			s += len;
			ss_array++;
		}
		else
			s++;
	}
	return (1);
}

static size_t	count_ss(char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			while (*s && *s++ != c)
				;
		}
		else
			s++;
	}
	return (n);
}

char	**splitstr(char const *s, char c)
{
	int		n;
	char	**ss_array;

	n = count_ss((char *)s, c);
	ss_array = (char **)malloc(sizeof(char *) * (n + 1));
	if (!ss_array)
		return (NULL);
	ss_array[n] = NULL;
	if (!store_ss(ss_array, (char *)s, c))
	{
		free(ss_array);
		return (NULL);
	}
	return (ss_array);
}

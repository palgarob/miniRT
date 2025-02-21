/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2i.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 12:00:10 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/28 15:51:00 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_spaces(char *s)
{
	size_t	i;

	i = 0;
	while (*s == ' ' || *s == '\t' || *s == '\v'
		|| *s == '\f' || *s == '\r' || *s == '\n')
	{
		i++;
		s++;
	}
	return (i);
}

static int	check_overflow(long aux, int *n)
{
	if (aux > 2147483647 || aux < -2147483648)
		return (1);
	else
	{
		if (n)
			*n = aux;
		return (0);
	}
}

long	convert_to_long(char *str)
{
	long	l;

	l = 0;
	while (ft_isdigit(*str))
	{
		l = l * 10 + (*str - '0');
		str++;
	}
	return (l);
}

int	a2i(char *str, int *n)
{
	long	aux;

	str += count_spaces(str);
	if (*str == '-')
		aux = convert_to_long(str + 1) * -1;
	else if (*str == '+')
		aux = convert_to_long(str + 1);
	else if (ft_isdigit(*str))
		aux = convert_to_long(str);
	else
		return (1);
	return (check_overflow(aux, n));
}

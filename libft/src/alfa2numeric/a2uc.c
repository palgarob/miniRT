/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a2uc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:59:48 by pepaloma          #+#    #+#             */
/*   Updated: 2024/11/28 16:54:41 by pepaloma         ###   ########.fr       */
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

static int	check_overflow(long long aux, unsigned char *n)
{
	if (aux > 255 || aux < 0)
		return (1);
	else
	{
		*n = aux;
		return (0);
	}
}

long long	convert2ll(char *str)
{
	long long	l;

	l = 0;
	while (ft_isdigit(*str))
	{
		l = l * 10 + (*str - '0');
		str++;
	}
	return (l);
}

int	a2uc(char *str, unsigned char *n)
{
	long long	aux;

	str += count_spaces(str);
	if (*str == '-')
		aux = convert2ll(str + 1) * -1;
	else if (*str == '+')
		aux = convert2ll(str + 1);
	else if (ft_isdigit(*str))
		aux = convert2ll(str);
	else
		return (1);
	return (check_overflow(aux, n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:40:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 11:18:59 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	factor_loop(const char *s, double *result)
{
	double	factor;

	factor = 1.0;
	while (*++s && ft_isdigit(*s))
	{
		factor /= 10;
		*result += (*s - '0') * factor;
	}
}

double	to_double(const char *str)
{
	const char	*s;
	double		result;
	int			sign;

	s = str;
	result = 0.0;
	sign = 1;
	while (*s && *s == ' ')
		s++;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	--s;
	while (*++s && ft_isdigit(*s))
		result = result * 10 + (*s - '0');
	if (*s == '.')
		factor_loop(s, &result);
	result *= sign;
	return (result);
}

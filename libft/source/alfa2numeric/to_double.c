/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:40:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/07 10:57:30 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double to_double(const char *str)
{
	const char *s;
	double result;
	double factor;
	int sign;

	s = str;
	result = 0.0;
	factor = 1.0;
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
		while (*++s && ft_isdigit(*s))
			result = result + (*s - '0') * (factor /= 10);
	result *= sign;
	return (result);
}

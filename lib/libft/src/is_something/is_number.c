/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:59 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 11:21:59 by muribe-l         ###   ########.fr       */
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

bool	is_number(char *str)
{
	str += count_spaces(str);
	return (
		ft_isdigit(*str)
		|| ((*str == '+' || *str == '-') && ft_isdigit(*(str + 1)))
	);
}

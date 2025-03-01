/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:07:16 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/01 11:39:40 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_loop(const char *str)
{
	int	i;
	int	dots;

	i = -1;
	dots = 0;
	while (str[++i])
	{
		if (str[i] == '.')
			dots++;
		if (!ft_isdigit(str[i]) && str[i] != '.' && str[i] != '\n'
			&& !(i == 0 && (str[i] == '+' || str[i] == '-')))
			return (false);
	}
	if (dots > 1)
		return (false);	
	return (true);
}

bool	is_double(const char *str)
{
	char	**split;
	int		i;

	if (!str || !*str)
		return (false);
	if (!check_loop(str))
		return (false);
	split = splitstr(str, '.');
	if (!split)
		return (false);
	if (splitlen(split) == 1 && is_number(split[0]))
		return (splitfree(split), true);
	if (splitlen(split) != 2)
		return (splitfree(split), false);
	if (split[0][0] == '-' && split[0][1] == '\0')
		return (splitfree(split), false);
	if (split[0][0] == '-' && !is_number(split[0] + 1))
		return (splitfree(split), false);
	if (split[0][0] != '-' && !is_number(split[0]))
		return (splitfree(split), false);
	i = -1;
	while (split[1][++i])
		if (!ft_isdigit(split[1][i]))
			return (splitfree(split), false);
	return (splitfree(split), true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:54:52 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/19 23:37:42 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	good_format(char **split)
{
	int	i;
	int	n;

	if (splitlen(split) != 3
		|| !is_double(split[0])
		|| !is_double(split[1])
		|| !is_double(split[2]))
		return (0);
	i = -1;
	while (++i < 3)
	{
		n = ft_atoi(split[i]);
		if (n < 0 || n > 255)
			return (0);
	}
	return (1);
}

bool	is_rgb(t_color *dst, char *org)
{
	char	**split;

	split = splitstr(org, ',');
	if (!split)
		return (false);
	if (!good_format(split))
		return (splitfree(split), false);
	*dst = color(to_double(split[0]) / 255.0, to_double(split[1]) / 255.0,
			to_double(split[2]) / 255.0);
	return (splitfree(split), true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:56:18 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 11:19:21 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	good_format(char **split)
{
	int	i;

	if (splitlen(split) != 3)
		return (0);
	i = -1;
	while (++i < 3)
		if (!is_double(split[i]))
			return (0);
	return (1);
}

bool	is_coord(t_vec *dst, char *src)
{
	char	**split;

	split = splitstr(src, ',');
	if (!split)
		return (false);
	if (!good_format(split))
		return (splitfree(split), false);
	dst->x = to_double(split[0]);
	dst->y = to_double(split[1]);
	dst->z = to_double(split[2]);
	return (splitfree(split), true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normalized_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:05 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 11:20:23 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_normalized_vec(char *vec)
{
	int		i;
	char	**split;

	split = splitstr(vec, ',');
	i = -1;
	while (split[++i])
	{
		if (!is_double(split[i])
			|| to_double(split[i]) < -1.0
			|| to_double(split[i]) > 1.0)
			return (splitfree(split), 0);
	}
	return (splitfree(split), 1);
}

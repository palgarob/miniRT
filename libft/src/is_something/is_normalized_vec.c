/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_normalized_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:57:05 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/07 10:57:16 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_normalized_vec(char *vec)
{
	int i;
	char **split;

	split = splitstr(vec, ',');
	i = -1;
	while (split[++i])
	{
		if (!is_double(split[i]) || to_double(split[i]) < -1.0 || to_double(split[i]) > 1.0)
			return (splitfree(split), 0);
	}
	return (splitfree(split), 1);
}

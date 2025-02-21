/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:04:35 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 16:38:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	matrix_inverse(double mat4[4][4], double inv[4][4])
{
	double	determinant;
	int		i;
	int		j;

	determinant = matrix4_det(mat4);
	if (determinant == 0)
		return (false);
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			inv[i][j] = matrix4_cofactor(mat4, j, i) / determinant;
			i++;
		}
		j++;
	}
	return (true);
}

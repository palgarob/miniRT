/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:53:58 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 00:13:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	matrix_multiply(double **a, double **b, size_t size, double **result)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			result[i][j] = a[i][0] * b[0][j]
				+ a[i][1] * b[1][j]
				+ a[i][2] * b[2][j]
				+ a[i][3] * b[3][j];
			i++;
		}
		j++;
	}
}

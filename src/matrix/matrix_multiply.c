/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:53:58 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 14:14:54 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	matrix_multiply(double a[4][4], double b[4][4], double result[4][4])
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
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

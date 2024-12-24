/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 08:40:15 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 13:55:47 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_row(double mat3[3][3], double mat2[2][2], int column, int *jk)
{
	int	i;
	int	l;
	
	l = 0;
	i = 0;
	while (l < 2)
	{
		if (i != column)
		{
			mat2[jk[1]][l] = mat3[jk[0]][i];
			l++;
		}
		i++;
	}
}

void	submatrix3(double mat3[3][3], double mat2[2][2], int row, int column)
{
	int	jk[2];

	jk[0] = 0;
	jk[1]= 0;
	while (jk[1] < 2)
	{
		if (jk[0] != row)
		{
			add_row(mat3, mat2, column, jk);
			jk[1]++;
		}
		jk[0]++;
	}
}

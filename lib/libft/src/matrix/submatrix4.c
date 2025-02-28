/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   submatrix4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 01:21:54 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 11:24:18 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_row(double mat4[4][4], double mat3[3][3], int column, int *jk)
{
	int	i;
	int	l;

	l = 0;
	i = 0;
	while (l < 3)
	{
		if (i != column)
		{
			mat3[jk[1]][l] = mat4[jk[0]][i];
			l++;
		}
		i++;
	}
}

void	submatrix4(double mat4[4][4], double mat3[3][3], int row, int column)
{
	int	jk[2];

	jk[0] = 0;
	jk[1] = 0;
	while (jk[1] < 3)
	{
		if (jk[0] != row)
		{
			add_row(mat4, mat3, column, jk);
			jk[1]++;
		}
		jk[0]++;
	}
}

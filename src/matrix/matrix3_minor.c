/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_minor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 08:37:20 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 13:31:14 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	matrix3_minor(double mat3[3][3], int row, int column)
{
	double	mat2[2][2];

	submatrix3(mat3, mat2, row, column);
	return (matrix2_det(mat2));
}

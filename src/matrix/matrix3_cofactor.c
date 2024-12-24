/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_cofactor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 08:46:56 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 08:52:17 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	matrix3_cofactor(double **mat3, int row, int column)
{
	if ((row + column) % 2)
		return (-matrix3_minor(mat3, row, column));
	return (matrix_minor(mat3, row, column));
}

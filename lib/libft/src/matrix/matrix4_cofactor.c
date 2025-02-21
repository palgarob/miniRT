/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_cofactor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:42:14 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 16:38:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	matrix4_cofactor(double mat4[4][4], int row, int column)
{
	if ((row + column) % 2)
		return (-matrix4_minor(mat4, row, column));
	return (matrix4_minor(mat4, row, column));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_det.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:39:39 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 13:29:51 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	matrix4_det(double mat4[4][4])
{
	return (
		mat4[0][0] * matrix4_cofactor(mat4, 0, 0)
		+ mat4[0][1] * matrix4_cofactor(mat4, 0, 1)
		+ mat4[0][2] * matrix4_cofactor(mat4, 0, 2)
		+ mat4[0][3] * matrix4_cofactor(mat4, 0, 3)
	);
}

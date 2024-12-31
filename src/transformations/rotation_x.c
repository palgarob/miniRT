/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:10:52 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/30 11:54:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rotation_x(double mat[4][4], double degrees)
{
	double	rad;

	rad = deg2rad(degrees);
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = 0;
	mat[1][0] = 0;
	mat[1][1] = cos(rad);
	mat[1][2] = -sin(rad);
	mat[1][3] = 0;
	mat[2][0] = 0;
	mat[2][1] = sin(rad);
	mat[2][2] = cos(rad);
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

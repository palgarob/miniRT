/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:31:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:49:23 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transformation(double mat[4][4], t_transformation *t, t_obj_type type)
{
	double	rotat_mat[4][4];
	double	trans_mat[4][4];
	double	scale_mat[4][4];
	t_vec	aux;

	aux = t->location;
	translation(trans_mat, &aux);
	if (type == LIGHT || type == PLANE || type == CAMERA)
		matrix_get_identity(scale_mat);
	else
	{
		if (type == SPHERE)
		{
			aux = vec(t->diameter / 2, t->diameter / 2, t->diameter / 2);
			scaling(scale_mat, &aux);
		}
		else if (type == CYLINDER)
		{
			aux = vec(t->height, t->diameter / 2, t->diameter / 2);
			scaling(scale_mat, &aux);
		}
	}
	if (type == SPHERE)
		matrix_get_identity(rotat_mat);
	else
	{
		aux = t->orientation;
		rotation(rotat_mat, &aux);
	}
	matrix_multiply(trans_mat, rotat_mat, mat);
	matrix_multiply(mat, scale_mat, trans_mat);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:38:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/09 10:14:08 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_rotation(t_object *o, double trans[4][4])
{
	if (o->type == SPHERE)
		matrix_get_identity(trans);
	matrix_get_identity(trans);
}

static void	get_scale(t_object *o, double trans[4][4])
{
	if (o->type == PLANE)
		matrix_get_identity(trans);
	matrix_get_identity(trans);
}

static void	get_translation(t_object *o, double trans[4][4])
{
	translation(trans, o->location.x, o->location.y, o->location.z);
}

static void	get_transformation(t_object *o, double transformation[4][4])
{
	double	translation[4][4];
	double	rotation[4][4];
	double	scale[4][4];

	get_rotation(o, rotation);
	get_scale(o, scale);
	get_translation(o, translation);
	matrix_multiply(rotation, scale, transformation);
	matrix_multiply(transformation, translation, rotation);
	matrix_cpy(rotation, transformation);
}

bool	ray_intersect_object(t_ray *r, t_object *o, t_intsect *x)
{
	t_ray	new_ray;
	double	transformation[4][4];

	get_transformation(o, transformation);
	transform_ray(r, transformation, &new_ray);
	x->t1 = -1;
	x->t2 = -1;
	if (o->type == SPHERE)
		find_sp_intersection(r, o, x);
	if (x->t1 > 0 || x->t2 > 0)
		return (true);
	return (false);
}

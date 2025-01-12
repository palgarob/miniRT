/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:38:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/12 09:00:09 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_rotation(t_object *o, double trans[4][4])
{
	if (o->type == SPHERE)
		matrix_get_identity(trans);
	else
		rotation(trans, &o->orientation);
}

static void	get_scale(t_object *o, double trans[4][4])
{
	if (o->type == PLANE)
		matrix_get_identity(trans);
	else
		scaling(trans, o->diameter / 2, o->diameter / 2, o->diameter / 2);
}

static void	get_translation(t_object *o, double trans[4][4])
{
	translation(trans, o->location.x, o->location.y, o->location.z);
}

static void	get_transformation(t_object *o, double transformation[4][4])
{
	double	trans[4][4];
	double	rotation[4][4];
	double	scale[4][4];
	double	aux[4][4];

	get_scale(o, scale);
	get_translation(o, trans);
	get_rotation(o, rotation);
	matrix_multiply(trans, rotation, aux);
	matrix_multiply(aux, scale, trans);
	matrix_inverse(trans, transformation);
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
		find_sp_intersection(&new_ray, o, x);
	if (x->t1 > 0 || x->t2 > 0)
	{
		x->object = o;
		return (true);
	}
	return (false);
}

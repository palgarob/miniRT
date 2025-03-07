/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:38:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/21 22:58:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	normal_at(t_object *o, t_pnt world_point)
{
	t_pnt	object_point;
	t_vec	object_normal;
	t_vec	world_normal;
	double	inv[4][4];

	matrix_inverse(o->mat, inv);
	if (o->type == SPHERE)
	{
		object_point = tpl_multiply_matrix(inv, world_point);
		object_normal = vec_from_to(pnt(0, 0, 0), object_point);
	}
	else if (o->type == PLANE)
		object_normal = vec(0, 0, 1);
	else
	{
		object_point = tpl_multiply_matrix(inv, world_point);
		object_normal = vec(object_point.x, object_point.y, 0);
	}
	matrix4_transpose(inv);
	world_normal = tpl_multiply_matrix(inv, object_normal);
	world_normal.w = 0;
	return (vec_normalize(world_normal));
}

static bool	negate_ahead(t_ray *new_ray, t_object *o, double t[2], t_intsect *x)
{
	if (t[0] > 0)
	{
		x->t = t[0];
		x->normal = normal_at(o, ray_position(new_ray, x->t));
		x->interior_hit = false;
		return (true);
	}
	else if (t[1] > 0)
	{
		x->t = t[1];
		x->normal = tpl_negate(normal_at(o, ray_position(new_ray, x->t)));
		x->interior_hit = true;
		return (true);
	}
	else
		return (false);
}

static bool	inters_ahead(t_ray *new_ray, t_object *o, double t[2], t_intsect *x)
{
	x->object = o;
	if (o->type == PLANE)
	{
		if (t[0] > 0)
		{
			x->t = t[0];
			x->normal = normal_at(o, ray_position(new_ray, x->t));
			if (vec_dot(x->normal, new_ray->direction) > 0)
				x->normal = tpl_negate(x->normal);
			x->interior_hit = false;
			return (true);
		}
		else
			return (false);
	}
	else
	{
		return (negate_ahead(new_ray, o, t, x));
	}
}

bool	ray_intersect_object(t_ray *r, t_object *o, t_intsect *x)
{
	t_ray	new_ray;
	double	inv[4][4];
	double	t[2];

	matrix_inverse(o->mat, inv);
	transform_ray(r, inv, &new_ray);
	if ((o->type == SPHERE && sp_is_intersected(&new_ray, t))
		|| (o->type == PLANE && pl_is_intersected(&new_ray, t))
		|| (o->type == CYLINDER && cy_is_intersected(&new_ray, t)))
	{
		return (inters_ahead(r, o, t, x));
	}
	else
		return (false);
}

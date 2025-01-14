/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect_object.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:38:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 21:55:53 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ray_intersect_object(t_ray *r, t_object *o, t_intsect *x)
{
	t_ray	new_ray;
	double	inv[4][4];

	matrix_inverse(o->mat, inv);
	transform_ray(r, inv, &new_ray);
	x->t1 = -1;
	x->t2 = -1;
	if (o->type == SPHERE)
		find_sp_intersection(&new_ray, o, x);
	/* else if (o->type == PLANE)
		find_pl_intersection(&new_ray, o, x);
	else if (o->type == CYLINDER)
		find_cy_intersection(&new_ray, o, x); */
	if (x->t1 > 0 || x->t2 > 0)
	{
		x->object = o;
		return (true);
	}
	return (false);
}

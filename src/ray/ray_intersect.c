/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:38:37 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/31 21:23:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ray_intersect(t_ray *r, t_object *o, t_intersection *x)
{
	t_ray	new_ray;
	double	inv[4][4];

	matrix_inverse(o->transformation, inv);
	transform_ray(r, inv, &new_ray);
	x->t1 = -1;
	x->t2 = -1;
	if (o->type == SPHERE)
		find_sp_intersection(r, o, x);
	if (x->t1 > 0 || x->t2 > 0)
		return (true);
	return (false);
}

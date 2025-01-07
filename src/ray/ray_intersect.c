/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:38:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/07 12:12:31 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	get_transformation(t_object *o, double transformation[4][4])
{
	
}

bool	ray_intersect(t_ray *r, t_object *o, t_intersection *x)
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

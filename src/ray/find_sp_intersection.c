/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sp_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:22:22 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/30 15:55:55 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_sp_intersection(t_ray *r, t_object *o, t_intersection *h)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	from_to;

	from_to = vec_from_to(o->location, r->origin);
	a = vec_dot(r->direction, r->direction);
	b = 2 * vec_dot(r->direction, from_to);
	c = vec_dot(from_to, from_to);
	d = pow(b, 2) - 4 * a * c;
	if (d < 0.0)
		return ;
	h->t1 = (-b - sqrt(d)) / (2 * a);
	h->t2 = (-b + sqrt(d)) / (2 * a);
}

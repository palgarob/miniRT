/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_is_intersected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:22:22 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 12:12:35 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	sp_is_intersected(t_ray *r, double t[2])
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_vec	from_to;

	from_to = vec_from_to(pnt(0, 0, 0), r->origin);
	a = vec_dot(r->direction, r->direction);
	b = 2 * vec_dot(r->direction, from_to);
	c = vec_dot(from_to, from_to) - 1;
	d = pow(b, 2) - 4 * a * c;
	if (d < 0.0)
		return (false);
	t[0] = (-b - sqrt(d)) / (2 * a);
	t[1] = (-b + sqrt(d)) / (2 * a);
	if (t[0] > t[1])
	{
		a = t[1];
		t[1] = t[0];
		t[0] = a;
	}
	return (true);
}

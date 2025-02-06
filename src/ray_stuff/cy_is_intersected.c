/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_is_intersected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:55:10 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/06 19:39:05 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	cy_is_intersected(t_ray *r, double t[2])
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = pow(r->direction.x, 2) + pow(r->direction.y, 2);
	if (fpn_compare(a, 0) == EQUAL)
		return (false);
	b = 2 * r->origin.x * r->direction.x + 2 * r->origin.y * r->direction.y;
	c = pow(r->origin.x, 2) + pow(r->origin.y, 2) - 1;
	d = pow(b, 2) - 4 * a * c;
	if (d < 0)
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

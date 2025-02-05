/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_is_intersected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:11:45 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/05 16:25:00 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	pl_is_intersected(t_ray *r, double t[2])
{
	//print_tpl(r->origin);
	//printf("%f ", r->direction.z);
	if (fpn_compare(r->direction.z, 0) == EQUAL)
		return (false);
	t[0] = -r->origin.z / r->direction.z;
	if (t[0] < 0)
		return (false);
	return (true);
}

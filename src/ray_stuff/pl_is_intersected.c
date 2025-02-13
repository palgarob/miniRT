/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_is_intersected.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:11:45 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/13 17:54:59 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	pl_is_intersected(t_ray *r, double t[2])
{
	if (fpn_compare(r->direction.z, 0) == EQUAL)
		return (false);
	t[0] = -r->origin.z / r->direction.z;
	if (t[0] < 0)
		return (false);
	return (true);
}

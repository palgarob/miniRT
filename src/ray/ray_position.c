/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 12:25:44 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/30 12:38:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pnt	ray_position(t_ray *ray, double t)
{
	return (tpl_add(ray->origin, tpl_multiply(ray->direction, t)));
}

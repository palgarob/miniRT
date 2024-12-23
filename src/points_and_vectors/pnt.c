/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:07:20 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:07:35 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pnt	pnt(double x, double y, double z)
{
	t_pnt	point;
	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
}

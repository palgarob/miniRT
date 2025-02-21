/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:07:20 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:47:07 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pnt	pnt(double x, double y, double z)
{
	t_pnt	point;
	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
}

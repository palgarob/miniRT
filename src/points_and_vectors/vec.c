/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:08:55 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:09:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec(double x, double y, double z)
{
	t_pnt	vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;
	return (vector);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_blend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:14:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/19 23:34:01 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	color_blend(t_color a, t_color b)
{
	a.r = fmin(1, a.r * b.r);
	a.g = fmin(1, a.g * b.g);
	a.b = fmin(1, a.b * b.b);
	return (a);
}

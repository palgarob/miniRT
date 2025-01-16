/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:25:38 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/16 14:22:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	lighting(t_data *data, t_ray *r, t_intsect *intsect)
{
	t_color	effective_color;
	t_vec	lightv;
	t_color	ambient;
	t_color	diffuse;
	double	light_dot_normal;

	effective_color = color_blend(intsect->object->color, color_mul(data->light->color, data->light->brightness));
	lightv = vec_normalize(vec_from_to(ray_position(r, intsect->t), data->light->location));
	ambient = color_mul(effective_color, data->ambient->ratio);
	light_dot_normal = vec_dot(lightv, intsect->normal);
	if (fpn_compare(light_dot_normal, 0) == A_LESST_B)
		diffuse = color(0, 0, 0);
	else
	{
		diffuse = color_mul(
			effective_color,
			light_dot_normal
		);
	}
	return (color_add(ambient, diffuse));
}

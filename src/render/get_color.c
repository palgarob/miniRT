/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/04 01:17:37 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_color(t_data *data, t_ray *r, t_intsect *intsect)
{
	t_material	m;
	t_pnt		p;

	
	m = material(intsect->object->color, 0.9, data->ambient, 50.0, 0.9);
	p = ray_position(r, intsect->t);
	return (lighting(&m, p, data->light, vec_normalize(vec_from_to(p, data->camera->location)), intsect->normal));
}

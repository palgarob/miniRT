/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/07 13:58:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	lighting(t_material *material, t_pnt p, t_light *l, t_vec e, t_vec n)
{
	t_color	effective_color;
	t_vec	lightv;
	t_color	ambient;
	double	light_dot_normal;
	t_color	diffuse;
	t_color	specular;
	t_vec	reflectv;
	double	reflect_dot_eye;
	double	factor;
	(void)e;

	effective_color = color_blend(material->c, color_mul(l->color, l->brightness));
	lightv = vec_normalize(vec_from_to(p, l->location));
	ambient = color_mul(material->a_color, material->a_ratio);
	light_dot_normal = fmax(0.0, vec_dot(lightv, n));
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0,0,0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = color_mul(effective_color, material->diffuse * light_dot_normal);
		reflectv = reflect(n, tpl_negate(lightv));
		reflect_dot_eye = vec_dot(reflectv, e);
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, material->shininess);
			specular = color_mul(l->color, factor * material->specular);
		}
	}
	return (color_add(ambient, color_add(diffuse, specular)));
}

t_color	get_color(t_data *data, t_ray *r, t_intsect *intsect)
{
	t_material	m;
	t_pnt		p;

	
	m = material(intsect->object->color, 0.9, data->ambient, 50.0, 0.9);
	p = ray_position(r, intsect->t);
	return (lighting(&m, p, data->light, vec_normalize(vec_from_to(p, data->camera->location)), intsect->normal));
}

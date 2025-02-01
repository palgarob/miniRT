/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:25:38 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/01 12:09:03 by pepaloma         ###   ########.fr       */
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

	effective_color = color_mul(material->c, l->brightness);
	lightv = vec_normalize(vec_from_to(p, l->location));
	ambient = color_mul(effective_color, material->ambient);
	light_dot_normal = vec_dot(lightv, n);
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0,0,0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = color_mul(effective_color, material->diffuse * light_dot_normal);
		reflectv = reflect(tpl_negate(lightv), n);
		reflect_dot_eye = vec_dot(reflectv, e);
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, material->shininess);
			specular = color_mul(color(l->brightness, l->brightness, l->brightness), material->specular * factor);
		}
	}
	return (color_add(ambient, color_add(diffuse, specular)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:25:38 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/03 07:17:02 by pepaloma         ###   ########.fr       */
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
//	t_vec	reflectv;
//	double	reflect_dot_eye;
//	double	factor;
	(void)e;

	effective_color = color_mul(material->c, l->brightness);
	lightv = vec_normalize(vec_from_to(p, l->location));
	ambient = color_mul(effective_color, material->ambient);
	light_dot_normal = fmax(0.0, vec_dot(lightv, n));
//	print_tpl(n);
	if (light_dot_normal < 0.0)
	{
		diffuse = color(0,0,0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = color_mul(effective_color, material->diffuse * light_dot_normal);
//		reflectv = reflect(n, tpl_negate(lightv));
//		reflect_dot_eye = vec_dot(reflectv, e);
			specular = color(0, 0, 0);
	}
	return (color_add(ambient, color_add(diffuse, specular)));
}

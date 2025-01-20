/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:25:38 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/20 09:27:03 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	lighting(t_data *data, t_ray *r, t_intsect *intsect)
{
	t_pnt	hit_point;
	
	hit_point = ray_position(r, intsect->t);
	
	/*
	t_color	effective_color = color_mul(intsect->object->teri.color, data->light->brightness);
	t_vec	lightv = vec_normalize(vec_sub(data->light->location, ray_position(r, intsect->t)));
	t_color	ambient = color_mul(effective_color, intsect->object->teri.ambient);
	double	light_dot_normal = vec_dot(lightv, tpl_negate(intsect->normal));
	t_color	diffuse;
	t_color	specular;
	t_vec	reflectv;
	double	reflect_dot_eye;
	double	factor;
	if (light_dot_normal < 0)
	{
		printfd(1, "hola");
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	else
	{
		diffuse = color_mul(effective_color, intsect->object->teri.diffuse * light_dot_normal);
		reflectv = reflect(intsect->normal, tpl_negate(lightv));
		reflect_dot_eye = vec_dot(reflectv, vec_normalize(vec_from_to(ray_position(r, intsect->t), tpl_multiply_matrix(intsect->object->mat, pnt(0, 0, 0)))));
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, intsect->object->teri.shininess);
			specular = color_mul(data->light->color, intsect->object->teri.specular * factor);
		}
	}
	effective_color = color_add(
			ambient,
			color_add(
				diffuse,
				specular
			)
		);
	return (effective_color);
	*/
	
/*

	printf("%f, %f, %f\n", effective_color.r, effective_color.g, effective_color.b);


	effective_color = color_mul(intsect->object->color, data->light->brightness);
	lightv = vec_normalize(vec_from_to(ray_position(r, intsect->t), data->light->location));
	ambient = color_mul(effective_color, data->ambient->ratio);
	light_dot_normal = vec_dot(lightv, intsect->normal);
	if (fpn_compare(light_dot_normal, 0) == A_LESST_B)
	{
		diffuse = color(0, 0, 0);
	}
	else
	{
		diffuse = color_mul(
			effective_color,
			light_dot_normal
		);
	}
	return (color_add(ambient, diffuse)); */
}

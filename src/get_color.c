/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 19:18:35 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color apply_diffuse(t_data *data, t_ray shadow, t_intsect *h, t_color color)
{
	double	diffuse_factor;
	t_color final;
	
	diffuse_factor = fmax(0.0, vec_dot(h->normal, shadow.direction));
	diffuse_factor *= data->light->brightness;
	final.r = fmin(255, color.r * (data->light->color.r / 255.0) * diffuse_factor);
	final.g = fmin(255, color.g * (data->light->color.g / 255.0) * diffuse_factor);
	final.b = fmin(255, color.b * (data->light->color.b / 255.0) * diffuse_factor);
	return (final);
}

t_color apply_ambient(t_data *data, t_color color)
{
	t_color final;

	final.r = fmin(255, (data->ambient->color.r / 255.0) * data->ambient->ratio * color.r);
	final.g = fmin(255, (data->ambient->color.g / 255.0) * data->ambient->ratio * color.g);
	final.b = fmin(255, (data->ambient->color.b / 255.0) * data->ambient->ratio * color.b);
	return (final);
}

t_color combine_lighting(t_color color1, t_color color2)
{
	t_color	finalColor;

	finalColor.r = fmin(255, color1.r + color2.r);
	finalColor.g = fmin(255, color1.g + color2.g);
	finalColor.b = fmin(255, color1.b + color2.b);
	return (finalColor);
}

int	is_in_shadow(t_data *data, t_ray *shadow, double light_distance)
{
	t_intsect	hit;

	if (intsect_is_found(data, shadow, &hit) && hit.t < light_distance)
		return (1);
	return (0);
}

t_color	cast_shadow_ray(t_vec intersection, t_data *data, t_intsect *h)
{
	t_vec	shadow_direction;
	t_ray	shadow_ray;
	double	light_distance;
	t_color	combined;
	t_pnt	light_location;

	light_location = tpl_multiply_matrix(data->light->mat, pnt(0, 0, 0));

	shadow_direction = vec_normalize(
			vec_sub(light_location, intersection));
	shadow_ray.origin = vec_add(intersection, tpl_multiply(h->normal, 1e-4));
	shadow_ray.direction = shadow_direction;
	light_distance = vec_len(vec_sub(light_location, intersection));
	if (is_in_shadow(data, &shadow_ray, light_distance))
		return (apply_ambient(data, h->object->color));
	combined = combine_lighting(
			apply_diffuse(data, shadow_ray, h, h->object->color),
			apply_ambient(data, h->object->color));
	return (combined);
}

t_color	get_color( t_data *data, t_ray *ray, t_intsect *intsect)
{
	return (cast_shadow_ray(ray_position(ray, intsect->t), data, intsect));
}

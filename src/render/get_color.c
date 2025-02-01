/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/01 12:45:34 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* t_color apply_diffuse(t_data *scene, t_ray shadow, t_intsect *h, t_color color)
{
	double	diffuse_factor;
	t_color final;
	
	diffuse_factor = fmax(0.0, vec_dot(h->normal, shadow.direction));
	diffuse_factor *= scene->light->brightness;
	final.r = fmin(1, color.r * scene->light->color.r * diffuse_factor);
	final.g = fmin(1, color.g * scene->light->color.g * diffuse_factor);
	final.b = fmin(1, color.b * scene->light->color.b * diffuse_factor);
	return (final);
}

t_color apply_ambient(t_data *scene, t_color color)
{
	t_color final;
	
	final.r = fmin(1, (scene->ambient->color.r) * scene->ambient->ratio * color.r);
	final.g = fmin(1, (scene->ambient->color.g) * scene->ambient->ratio * color.g);
	final.b = fmin(1, (scene->ambient->color.b) * scene->ambient->ratio * color.b);
	return (final);
}

t_color combine_lighting(t_color color1, t_color color2)
{
	t_color	finalColor;
	
	finalColor.r = fmin(1, color1.r + color2.r);
	finalColor.g = fmin(1, color1.g + color2.g);
	finalColor.b = fmin(1, color1.b + color2.b);
	return (finalColor);
}

int	is_in_shadow(t_data *data, t_ray *shadow, double light_distance)
{
	t_intsect	hit;

	if (intsect_is_found(data, shadow, &hit) && hit.t < light_distance)
		return (1);
	return (0);
}

t_color	cast_shadow_ray(t_vec intersection, t_data *scene, t_intsect *h)
{
	t_vec	shadow_direction;
	t_ray	shadow_ray;
	double	light_distance;
	t_color	combined;

	shadow_direction = vec_normalize(
			vec_sub(scene->light->location, intersection));
	shadow_ray.origin = vec_add(intersection, tpl_multiply(h->normal, 1e-4));
	shadow_ray.direction = shadow_direction;
	light_distance = vec_len(vec_sub(scene->light->location, intersection));
	if (is_in_shadow(scene, &shadow_ray, light_distance))
		return (apply_ambient(scene, h->object->color));
	combined = combine_lighting(
			apply_diffuse(scene, shadow_ray, h, h->object->color),
			apply_ambient(scene, h->object->color));
	return (combined);
} */

t_color	get_color(t_data *data, t_ray *r, t_intsect *intsect)
{
	t_material	m;
	t_pnt		p;

	m = material(intsect->object->color, 0.9, data->ambient->ratio, 200.0, 0.9);
	p = ray_position(r, intsect->t);
	return (lighting(&m, p, data->light, vec_normalize(vec_from_to(p, data->camera->location)), intsect->normal));
	// return (cast_shadow_ray(ray_position(r, intsect->t), data, intsect));
}

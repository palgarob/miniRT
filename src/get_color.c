/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/09 13:36:45 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* int	is_in_shadow(t_data *data, t_ray *shadow, double light_distance)
{
	t_hit	hit;

	if (intersect_is_found(data, shadow, &hit) && hit.t < light_distance)
		return (1);
	return (0);
}

t_color	cast_shadow_ray(t_vec3 intersection, t_data *scene, t_hit *h)
{
	t_vec3	shadow_direction;
	t_ray	shadow_ray;
	double	light_distance;
	t_color	combined;

	shadow_direction = vec_normalize(
			vec_sub(scene->light.location, intersection));
	shadow_ray.origin = vec_add(intersection, vec_scale_m(h->normal, 1e-4));
	shadow_ray.orientation = shadow_direction;
	light_distance = vec_len(vec_sub(scene->light.location, intersection));
	if (is_in_shadow(scene, &shadow_ray, light_distance))
		return (apply_ambient(scene, h->obj->color));
	combined = combine_lighting(
			apply_diffuse(scene, shadow_ray, h, h->obj->color),
			apply_ambient(scene, h->obj->color));
	return (combined);
} */

t_color	get_color(__attribute__((__unused__)) t_data *data, __attribute__((__unused__)) t_ray *ray, __attribute__((__unused__)) t_intsect *intsect)
{
	return (color(1, 1, 1));
}

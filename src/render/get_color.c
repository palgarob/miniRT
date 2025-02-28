/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:51:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 18:13:08 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	intsect_is_found(t_data *data, t_ray *r, t_intsect *aux)
{
	t_list		*object_list;
	t_intsect	min;

	min.object = NULL;
	min.t = INFINITY;
	aux->t = -1;
	object_list = data->objects;
	while (object_list)
	{
		if (ray_intersect_object(r, object_list->content, aux))
		{
			if (aux->t < min.t)
			{
				min = *aux;
			}
		}
		object_list = object_list->next;
	}
	if (min.object == NULL)
		return (false);
	*aux = min;
	return (true);
}

bool	is_shaded(t_pnt p, t_data *data, t_intsect *i)
{
	t_vec		v;
	double		distance;
	t_vec		direction;
	t_ray		r;
	t_intsect	aux;

	v = vec_from_to(p, data->light->location);
	distance = vec_len(v);
	direction = vec_normalize(v);
	r = ray(p, direction);
	if (!intsect_is_found(data, &r, &aux)
		|| (aux.object == i->object && !aux.interior_hit)
		|| fabs(aux.t - distance) < EPSILON
		|| aux.t > distance)
		return (false);
	return (true);
}

static t_color	diff_spec_calc(t_data *data, t_material *mat, t_lvars *lv)
{
	t_color	diffuse;
	t_color	specular;
	t_vec	reflectv;
	double	reflect_dot_eye;
	double	factor;

	if (lv->light_dn > 0.0 && !is_shaded(lv->p, data, lv->intsect))
	{
		diffuse = color_mul(lv->effec_color, mat->diffuse * lv->light_dn);
		reflectv = reflect(lv->intsect->normal, tpl_negate(lv->lightv));
		reflect_dot_eye = vec_dot(reflectv, lv->e);
		if (reflect_dot_eye <= 0)
			specular = color(0, 0, 0);
		else
		{
			factor = pow(reflect_dot_eye, mat->shininess);
			specular = color_mul(data->light->color, factor * mat->specular);
		}
	}
	else
	{
		diffuse = color(0, 0, 0);
		specular = color(0, 0, 0);
	}
	return (color_add(diffuse, specular));
}

t_color	lighting(t_data *data, t_material *material, t_lvars *lv)
{
	t_color	ambient;

	lv->effec_color = color_blend(material->c,
			color_mul(data->light->color, data->light->brightness));
	lv->lightv = vec_normalize(vec_from_to(lv->p, data->light->location));
	ambient = color_blend(lv->effec_color,
			color_mul(material->a_color, material->a_ratio));
	lv->light_dn = fmax(0.0, vec_dot(lv->lightv, lv->intsect->normal));
	return (color_add(ambient, diff_spec_calc(data, material, lv)));
}

t_color	get_color(t_data *data, t_ray *r, t_intsect *intsect)
{
	t_lvars		l;
	t_material	m;

	m.c = intsect->object->color;
	m.a_color = data->ambient->color;
	m.a_ratio = data->ambient->ratio;
	m.specular = 0.5;
	m.diffuse = 0.9;
	m.shininess = 50.0;
	l.p = ray_position(r, intsect->t);
	l.p = pnt_add(l.p, tpl_multiply(intsect->normal, EPSILON));
	l.e = vec_normalize(vec_from_to(l.p, data->camera->location));
	l.intsect = intsect;
	return (lighting(data, &m, &l));
}

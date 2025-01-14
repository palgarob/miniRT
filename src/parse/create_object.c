/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:08:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 14:08:25 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	init_sphere(t_transformation *t, t_object *obj, char **info_array)
{
	if (a2double(&t->diameter, info_array[2]))
		return (free(obj), 1);
	if (!is_rgb(&obj->color, info_array[3]))
		return (free(obj), 1);
	return (0);
}

static int	init_cyl(t_transformation *t, t_object *obj, char **info_array)
{
	if (!is_coord(&t->orientation, info_array[2]))
		return (free(obj), 1);
	if (a2double(&t->diameter, info_array[3]))
		return (free(obj), 1);
	if (a2double(&t->height, info_array[4]))
		return (free(obj), 1);
	if (!is_rgb(&obj->color, info_array[5]))
		return (free(obj), 1);
	return (0);
}

static int	init_plane(t_transformation *t, t_object *obj, char **info_array)
{
	if (!is_coord(&t->orientation, info_array[2]))
		return (free(obj), 1);
	if (!is_rgb(&obj->color, info_array[3]))
		return (free(obj), 1);
	return (0);
}

int	create_object(t_data *data, char **info_array, t_obj_type type)
{
	t_object			*obj;
	t_transformation	t;

	if (!is_coord(&t.location, info_array[1]))
		return (1);
	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (1);
	obj->type = type;
	if (type == SPHERE)
		return (init_sphere(&t, obj, info_array));
	if (type == CYLINDER)
		return (init_cyl(&t, obj, info_array));
	if (type == PLANE)
		return (init_plane(&t, obj, info_array));
	transformation(obj->mat, &t, obj->type);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
	return (0);
}

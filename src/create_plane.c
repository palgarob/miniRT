/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:28:58 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 02:29:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_plane(t_data *data, char **info_array)
{
	t_transformation	t;
	t_object			*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (1);
	obj->type = PLANE;
	if (!is_coord(&t.location, info_array[1]))
		return (1);
	if (!is_coord(&t.orientation, info_array[2]))
		return (free(obj), 1);
	if (!is_rgb(&obj->color, info_array[3]))
		return (free(obj), 1);
	transformation(obj->mat, &t, obj->type);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
	return (0);
}

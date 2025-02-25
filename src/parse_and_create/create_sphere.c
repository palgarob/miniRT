/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:08:04 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/21 22:16:19 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	apply_attributes(t_data *data, t_pnt loc, double d, t_object *obj)
{
	double	trans_mat[4][4];
	t_vec	scale_values;
	double	scale_mat[4][4];

	loc.w = 1;
	translation(trans_mat, &loc);
	scale_values = vec(d / 2, d / 2, d / 2);
	scaling(scale_mat, &scale_values);
	matrix_multiply(trans_mat, scale_mat, obj->mat);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
}

int	create_sphere(t_data *data, char **line_split)
{
	t_pnt		location;
	double		diameter;
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (1);
	obj->type = SPHERE;
	if (!is_coord(&location, line_split[1]))
		return (1);
	if (a2double(&diameter, line_split[2]))
		return (free(obj), 1);
	if (!is_rgb(&obj->color, line_split[3]))
		return (free(obj), 1);
	apply_attributes(data, location, diameter, obj);
	return (0);
}

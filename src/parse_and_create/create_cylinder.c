/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:28:12 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 19:05:53 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	apply_attributes(t_data *data, t_pnt loc, t_vec	val, t_object *obj)
{
	double		trans_mat[4][4];
	double		rotat_mat[4][4];
	double		scale_mat[4][4];
	double		aux[4][4];

	loc.w = 1;
	translation(trans_mat, &loc);
	obj->orientation.w = 0;
	obj->orientation = vec_normalize(obj->orientation);
	rotation(aux, &obj->orientation);
	matrix_inverse(aux, rotat_mat);
	scaling(scale_mat, &val);
	matrix_multiply(trans_mat, rotat_mat, aux);
	matrix_multiply(aux, scale_mat, obj->mat);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
}

int	create_cylinder(t_data *data, char **line_split)
{
	t_pnt		location;
	t_object	*obj;
	t_vec		values;
	double		diameter;
	double		height;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (1);
	obj->type = CYLINDER;
	if (!is_coord(&location, line_split[1])
		|| !is_coord(&obj->orientation, line_split[2])
		|| a2double(&diameter, line_split[3])
		|| a2double(&height, line_split[4])
		|| !is_rgb(&obj->color, line_split[5])
		|| !is_normalized_vec(obj->orientation))
	{
		free(obj);
		return (1);
	}
	values = vec(diameter / 2.0, diameter / 2.0, height);
	apply_attributes(data, location, values, obj);
	return (0);
}

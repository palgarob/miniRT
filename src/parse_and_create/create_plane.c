/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:28:58 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/13 17:52:37 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_plane(t_data *data, char **info_array)
{
	t_pnt		location;
	t_object	*obj;
	double		trans_mat[4][4];
	double		rotat_mat[4][4];

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (1);
	obj->type = PLANE;
	if (!is_coord(&location, info_array[1])
		|| !is_coord(&obj->orientation, info_array[2])
		|| !is_rgb(&obj->color, info_array[3]))
		return (free(obj), 1);
	translation(trans_mat, &location);
	obj->orientation = vec_normalize(obj->orientation);
	rotation(rotat_mat, &obj->orientation);
	matrix_multiply(trans_mat, rotat_mat, obj->mat);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
	return (0);
}

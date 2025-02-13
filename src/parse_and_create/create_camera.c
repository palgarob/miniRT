/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:31:26 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/13 17:51:38 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	setup_frame(t_data *data, double fov)
{
	int		image_height;
	double	frame_width;
	double	frame_height;

	image_height = IMAGE_WIDTH / ASPECT_RATIO;
	frame_width = tan(deg2rad(fov / 2)) * 2;
	frame_height = frame_width / ASPECT_RATIO;
	data->camera->ipix_width = frame_width / IMAGE_WIDTH;
	data->camera->ipix_height = frame_height / image_height;
	data->camera->offset_pixel = pnt(
			-frame_width / 2 + data->camera->ipix_width / 2,
			frame_height / 2 - data->camera->ipix_height / 2,
			FOCAL_LENGTH);
}

int	create_camera(t_data *data, char **line_split)
{
	t_vec	orientation;
	double	fov;
	double	trans_mat[4][4];
	double	rotat_mat[4][4];

	data->camera = (t_camera *)malloc(sizeof(t_camera));
	if (
		!is_coord(&data->camera->location, line_split[1])
		|| !is_coord(&orientation, line_split[2])
		|| a2double(&fov, line_split[3])
	)
		return (free(data->camera), 1);
	translation(trans_mat, &data->camera->location);
	rotation(rotat_mat, &orientation);
	matrix_multiply(trans_mat, rotat_mat, data->camera->mat);
	setup_frame(data, fov);
	return (0);
}

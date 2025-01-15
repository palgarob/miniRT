/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:31:26 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 02:32:05 by pepaloma         ###   ########.fr       */
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
	t_transformation	t;
	double				fov;

	if (
		!is_coord(&t.location, line_split[1])
		|| !is_coord(&t.orientation, line_split[2])
		|| a2double(&fov, line_split[3])
	)
		return (1);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	transformation(data->camera->mat, &t, CAMERA);
	setup_frame(data, fov);
	return (0);
}

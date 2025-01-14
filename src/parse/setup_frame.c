/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:09:06 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 14:09:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	setup_frame(t_data *data, double fov)
{
	int		image_height;
	double	frame_width;
	double	frame_height;

	image_height = IMAGE_WIDTH / ASPECT_RATIO;
	frame_width = tan(fov / 2 / DEG2RAD) * 2;
	frame_height = frame_width / ASPECT_RATIO;
	data->camera->ipix_width = frame_width / IMAGE_WIDTH;
	data->camera->ipix_height = frame_height / image_height;
	data->camera->offset_pixel = pnt(
		-frame_width / 2 + data->camera->ipix_width / 2,
		frame_height / 2 - data->camera->ipix_height / 2,
		FOCAL_LENGTH);
}

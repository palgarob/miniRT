/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:54:10 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	setup_frame(t_data *data, double fov)
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

int	create_camera(t_data *data, char **info_array)
{
	t_transformation	t;
	double				fov;

	if (
		ft_strcmp(info_array[0], "C")
		|| splitlen(info_array) != 4
		|| !is_coord(&t.location, info_array[1])
		|| !is_coord(&t.orientation, info_array[2])
		|| !a2double(&fov, info_array[3])
	)
		return (1);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	transformation(data->camera->mat, &t, CAMERA);
	setup_frame(data, fov);
	return (0);
}

int	create_light(t_data *data, char **info_array)
{
	t_transformation	t;
	double				fov;

	if (
		ft_strcmp(info_array[0], "L")
		|| splitlen(info_array) != 4
		|| !is_coord(&t.location, info_array[1])
		|| !a2double(&fov, info_array[3])
	)
		return (1);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	translation(data->light->mat, &t.location);
	setup_frame(data, fov);
	return (0);
}

int	create_ambient(t_data *data, char **info_array)
{
	if (
		ft_strcmp(info_array[0], "A")
		|| splitlen(info_array) != 3
		|| !is_rgb(&data->ambient->color, info_array[1])
		|| !a2double(&data->ambient->ratio, info_array[2])
	)
		return (1);
	return (0);
}

int	create_object(t_data *data, char **info_array)
{
	t_object			*obj;
	t_transformation	t;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (1);
	if (is_coord(&t.location, info_array[1]))
		return (free(obj), 1);
	if (ft_strcmp(info_array[0], "sp") && splitlen(info_array) != 4)
	{
		if (a2double(&t.diameter, info_array[2]))
			return (free(obj), 1);
		if (is_rgb(&obj->color, info_array[3]))
			return (free(obj), 1);
		obj->type = SPHERE;
	}
	else if (ft_strcmp(info_array[0], "cy") && splitlen(info_array) != 6)
	{
		if (is_coord(&t.orientation, info_array[2]))
			return (free(obj), 1);
		if (a2double(&t.diameter, info_array[3]))
			return (free(obj), 1);
		if (a2double(&t.height, info_array[4]))
			return (free(obj), 1);
		if (is_rgb(&obj->color, info_array[5]))
			return (free(obj), 1);
		obj->type = CYLINDER;
	}
	else if (ft_strcmp(info_array[0], "pl") && splitlen(info_array) != 4)
	{
		if (is_coord(&t.orientation, info_array[2]))
			return (free(obj), 1);
		if (is_rgb(&obj->color, info_array[3]))
			return (free(obj), 1);
		obj->type = PLANE;
	}
	transformation(obj->mat, &t, obj->type);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
	return (0);
}

int	parse_line(t_data *data, char *line)
{
	char	**info_array;

	info_array = splitstr(line, ' ');
	if (
		create_ambient(data, info_array)
		|| create_camera(data, info_array)
		|| create_light(data, info_array)
		|| create_object(data, info_array)
	)
	{
		splitfree(info_array);
		return (0);
	}
	else
	{
		printfd(STDERR_FILENO, BAD_ELEM_FORMAT);
		splitfree(info_array);
		return (1);
	}
}

void	parse(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	data->img_ptr = NULL;
	data->mlx_ptr = NULL;
	data->objects = NULL;
	data->camera = NULL;
	data->light = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printfd(STDERR_FILENO, BAD_OPEN);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(data, line))
		{
			free(line);
			exit(1);
		}
		line = get_next_line(fd);
	}
}


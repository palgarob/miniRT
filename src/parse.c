/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 22:24:02 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_sphere(char **split, t_data *data)
{
	t_object	*obj;

	if (splitlen(split) != 4)
		return (ft_dprintf(2, "Wrong sphere format in scene!\n"), 0);
	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (ft_dprintf(2, "obj malloc error!\n"), 0);
	obj->type = SPHERE;
	if (!assign_coords(&obj->location, split[1]))
		return (free(obj), ft_dprintf(2, "Invalid sphere coord!\n"), 0);
	if (!to_double(split[2]))
		return (free(obj), ft_dprintf(2, "Invalid sphere diameter!\n"), 0);
	obj->diameter = to_double(split[2]);
	if (!assign_rgb(&obj->color, split[3]))
		return (free(obj), ft_dprintf(2, "Invalid sphere RGB color!\n"), 0);
	ft_lstadd_back((t_list **)&data->objects, ft_lstnew(obj));
	return (1);
}

int	init_camera(char **split, t_data *data)
{
	if (data->camera.fov != -1)
		return (ft_dprintf(2, "More than one camera in scene!\n"), 0);
	if (splitlen(split) != 4)
		return (ft_dprintf(2, "Wrong camera format in scene!\n"), 0);
	if (!assign_coords(&data->camera.location, split[1]))
		return (ft_dprintf(2, "Invalid camera coord!\n"), 0);
	if (!is_normalized_vec(split[2])
		|| !assign_coords(&data->camera.orientation, split[2]))
		return (ft_dprintf(2, "Invalid camera orientation vector!\n"), 0);
	if (ft_atoi(split[3]) < 0 || ft_atoi(split[3]) > 180)
		return (ft_dprintf(2, "Invalid camera FOV!\n"), 0);
	data->camera.fov = ft_atoi(split[3]);
	return (1);
}

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

void	transformation(double mat[4][4], t_transformation *t, t_obj_type type)
{
	double	rotat_mat[4][4];
	double	trans_mat[4][4];
	double	scale_mat[4][4];
	t_vec	aux;

	aux = t->location;
	translation(trans_mat, &aux);
	if (type == LIGHT || type == PLANE || type == CAMERA)
		matrix_get_identity(scale_mat);
	else
	{
		if (type == SPHERE)
		{
			aux = vec(t->diameter / 2, t->diameter / 2, t->diameter / 2);
			scaling(scale_mat, &aux);
		}
		else if (type == CYLINDER)
		{
			aux = vec(t->height, t->diameter / 2, t->diameter / 2);
			scaling(scale_mat, &aux);
		}
	}
	if (type == SPHERE)
		matrix_get_identity(rotat_mat);
	else
	{
		aux = t->orientation;
		rotation(rotat_mat, &aux);
	}
	matrix_multiply(trans_mat, rotat_mat, mat);
	matrix_multiply(mat, scale_mat, trans_mat);
	matrix_inverse(trans_mat, mat);
}

int	create_camera(t_data *data, char **info_array)
{
	t_transformation	t;
	double				fov;

	if (
		ft_strcmp(info_array[0], "C")
		|| !is_coord(&t.location, info_array[1])
		|| !is_coord(&t.orientation, info_array[2])
		|| !a2double(&fov, info_array[3])
	)
		return (1);
	
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	transformation(data->camera->mat, &t, CAMERA);
	setup_frame(data, fov);
}

int	create_light(t_data *data, char **info_array)
{
	t_transformation	t;
	double				fov;

	if (
		ft_strcmp(info_array[0], "L")
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
	t_color	c;
	double	ratio;

	if (
		ft_strcmp(info_array[0], "A")
		|| !is_rgb(&data->ambient->color, info_array[1])
		|| !a2double(&data->ambient->ratio, info_array[2])
	)
		return (1);
}

int	create_object(t_data *data, char **info_array, t_obj_type type)
{
	
}

int	parse_line(t_data *data, char *line)
{
	char	**info_array;

	info_array = splitstr(line, ' ');
	if (
		create_ambient(data, info_array)
		|| create_camera(data, info_array)
		|| create_light(data, info_array)
		|| create_object(data, info_array, SPHERE)
		|| create_object(data, info_array, PLANE)
		|| create_object(data, info_array, CYLINDER)
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
			free_data(data);
			free(line);
			exit(1);
		}
		line = get_next_line(fd);
	}
}


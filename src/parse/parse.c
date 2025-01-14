/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 14:08:57 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_camera(t_data *data, char **info_array)
{
	t_transformation	t;
	double				fov;

	if (
		!is_coord(&t.location, info_array[1])
		|| !is_coord(&t.orientation, info_array[2])
		|| a2double(&fov, info_array[3])
	)
		return (1);
	data->camera = (t_camera *)malloc(sizeof(t_camera));
	transformation(data->camera->mat, &t, CAMERA);
	setup_frame(data, fov);
	return (0);
}

int	create_light(t_data *data, char **info_array)
{
	t_vec	v;

	data->light = (t_light *)malloc(sizeof(t_light));
	if (
		!is_coord(&v, info_array[1])
		|| a2double(&data->light->brightness, info_array[2])
		|| !is_rgb(&data->light->color, info_array[3])
	)
		return (free(data->light), 1);
	translation(data->light->mat, &v);
	return (0);
}

int	create_ambient(t_data *data, char **info_array)
{
	data->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (
		a2double(&data->ambient->ratio, info_array[1])
		|| !is_rgb(&data->ambient->color, info_array[2])
	)
		return (free(data->ambient), 1);
	return (0);
}

int	parse_line(t_data *data, char *line)
{
	char	**info_array;

	info_array = splitstr(line, ' ');
	if (!ft_strcmp(info_array[0], "A") && splitlen(info_array) == 3
		&& !create_ambient(data, info_array))
		return (splitfree(info_array), 0);
	else if (!ft_strcmp(info_array[0], "C") && splitlen(info_array) == 4
		&& !create_camera(data, info_array))
		return (splitfree(info_array), 0);
	else if (!ft_strcmp(info_array[0], "L") && splitlen(info_array) == 4
		&& !create_light(data, info_array))
		return (splitfree(info_array), 0);
	else if (!ft_strcmp(info_array[0], "sp") && splitlen(info_array) == 4
		&& !create_object(data, info_array, SPHERE))
		return (splitfree(info_array), 0);
	else if (!ft_strcmp(info_array[0], "cy") && splitlen(info_array) == 6
		&& !create_object(data, info_array, CYLINDER))
		return (splitfree(info_array), 0);
	else if (!ft_strcmp(info_array[0], "pl") && splitlen(info_array) == 4
		&& !create_object(data, info_array, PLANE))
		return (splitfree(info_array), 0);
	else
		return (splitfree(info_array),
			printfd(STDERR_FILENO, BAD_ELEM_FORMAT), 1);
}

void	parse(t_data *data, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printfd(STDERR_FILENO, BAD_OPEN);
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (*line != '\n' && parse_line(data, line))
		{
			free(line); //limpiar contenidos
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
}


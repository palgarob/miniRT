/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:45:22 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	create_light(t_data *data, char **line_split)
{
	t_vec	location;

	data->light = (t_light *)malloc(sizeof(t_light));
	if (
		!is_coord(&location, line_split[1])
		|| a2double(&data->light->brightness, line_split[2])
		|| !is_rgb(&data->light->color, line_split[3])
	)
		return (free(data->light), 1);
	translation(data->light->mat, &location);
	return (0);
}

int	create_ambient(t_data *data, char **line_split)
{
	data->ambient = (t_ambient *)malloc(sizeof(t_ambient));
	if (
		a2double(&data->ambient->ratio, line_split[1])
		|| !is_rgb(&data->ambient->color, line_split[2])
	)
		return (free(data->ambient), 1);
	return (0);
}

int	parse_line(t_data *data, char *line)
{
	char	**line_split;

	line_split = splitstr(line, ' ');
	if (!ft_strcmp(line_split[0], "A") && splitlen(line_split) == 3
		&& !create_ambient(data, line_split))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "C") && splitlen(line_split) == 4
		&& !create_camera(data, line_split))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "L") && splitlen(line_split) == 4
		&& !create_light(data, line_split))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "sp") && splitlen(line_split) == 4
		&& !create_object(data, line_split, SPHERE))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "cy") && splitlen(line_split) == 6
		&& !create_object(data, line_split, CYLINDER))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "pl") && splitlen(line_split) == 4
		&& !create_object(data, line_split, PLANE))
		return (splitfree(line_split), 0);
	else
		return (splitfree(line_split),
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


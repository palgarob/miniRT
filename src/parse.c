/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/09 13:42:13 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	assign_rgb(t_color *dst, char *org)
{
	char	**split;

	split = splitstr(org, ',');
	if (!split)
		return (ft_printf("Split error\n"), 0);
	if (!is_rgb(split))
		return (splitfree(split), 0);
	*dst = color(ft_atoi(split[0]), ft_atoi(split[1]),
			ft_atoi(split[2]));
	return (splitfree(split), 1);
}

int	assign_coords(t_vec *dst, char *org)
{
	char **split;

	split = splitstr(org, ',');
	if (!split)
		return (ft_printf("Split error\n"), 0);
	if (!is_coord(split))
		return (splitfree(split), 0);
	dst->x = to_double(split[0]);
	dst->y = to_double(split[1]);
	dst->z = to_double(split[2]);
	return (splitfree(split), 1);
}

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

static int	create_object(char **split, t_data *scene)
{
	if (!split)
		return (ft_dprintf(2, "Split error\n"), 0);
	if (!split[0])
		return (1);
	/* if (ft_strcmp(split[0], "A") == 0)
		return (init_ambient(split, scene)); */
	if (ft_strcmp(split[0], "C") == 0)
		return (init_camera(split, scene));
	/* if (ft_strcmp(split[0], "L") == 0)
		return (init_light(split, scene)); */
	if (ft_strcmp(split[0], "sp") == 0)
		return (init_sphere(split, scene));
	/* if (ft_strcmp(split[0], "pl") == 0)
		return (init_plane(split, scene));
	if (ft_strcmp(split[0], "cy") == 0)
		return (init_cylinder(split, scene)); */
	return (ft_dprintf(2, "%s is not supported in the scene!\n", split[0]), 0);
}

/* 
Set the camera light and ambiens to -1 to know if they've been previously set 
*/
static void	set_start_values(t_data *scene)
{
	/* scene->ambient.ratio = -1.0;
	scene->light.brightness = -1.0; */
	scene->objects = NULL;
	scene->camera.fov = -1;
}

static char	**get_buffer(char *file)
{
	int		fd;
	int		rbytes;
	char	buffer[777777];
	char	**split;

	ft_bzero(buffer, 777777);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (close(fd),
			ft_dprintf(2, "Error opening file"), NULL);
	rbytes = read(fd, buffer, 777777);
	if (rbytes == -1)
		return (close(fd),
			ft_dprintf(2, "Error reading file\n"),
			ft_bzero(buffer, 777777), NULL);
	split = splitstr(buffer, '\n');
	if (!split)
		return (close(fd), ft_dprintf(2, "Split error\n"), NULL);
	return (close(fd), split);
}

static int	read_file(char *file, t_data *scene)
{
	char	**lines;
	char	**split;
	int		i;

	set_start_values(scene);
	lines = get_buffer(file);
	if (lines == NULL)
		return (0);
	i = -1;
	while (lines[++i])
	{
		split = splitstr(lines[i], ' ');
		if (!create_object(split, scene))
			return (splitfree(lines), splitfree(split), 0);
		splitfree(split);
	}
	splitfree(lines);
	return (1);
}

void	parse(t_data *data, char *filename)
{
	if (!read_file(filename, data))
	{
		if (data->objects)
			ft_lstclear(&data->objects, free);
		exit(1);
	}
}


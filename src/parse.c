/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:19:48 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 02:32:37 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		&& !create_sphere(data, line_split))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "cy") && splitlen(line_split) == 6
		&& !create_cylinder(data, line_split))
		return (splitfree(line_split), 0);
	else if (!ft_strcmp(line_split[0], "pl") && splitlen(line_split) == 4
		&& !create_plane(data, line_split))
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


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:30:32 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 02:30:40 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

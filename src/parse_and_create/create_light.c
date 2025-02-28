/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:30:32 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 18:08:59 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_light(t_data *data, char **line_split)
{
	data->light = (t_light *)malloc(sizeof(t_light));
	if (
		!is_coord(&data->light->location, line_split[1])
		|| a2double(&data->light->brightness, line_split[2])
		|| data->light->brightness < 0.0 || data->light->brightness > 1.0
		|| !is_rgb(&data->light->color, line_split[3])
	)
		return (free(data->light), 1);
	data->light->location.w = 1;
	return (0);
}

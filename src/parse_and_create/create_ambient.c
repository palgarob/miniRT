/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 02:29:56 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 02:30:18 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

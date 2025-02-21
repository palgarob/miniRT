/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:36:53 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/21 22:48:18 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_data(t_data *data)
{
	if (data->ambient)
		free(data->ambient);
	if (data->camera)
		free(data->camera);
	if (data->light)
		free(data->light);
	if (data->objects)
	{
		ft_lstclear(&data->objects, free);
	}
		free(data->objects);
}

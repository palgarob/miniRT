/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:32:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/10 20:44:58 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


static void	write_pixel(t_color color, uint8_t *pixel)
{
	ft_memset(pixel, color.r * 255, 1);
	ft_memset(pixel + 1, color.g * 255, 1);
	ft_memset(pixel + 2, color.b * 255, 1);
	ft_memset(pixel + 3, 255, 1);
}
static bool	intsect_is_found(t_data *data, t_ray *r, t_intsect *aux)
{
	t_list		*object_list;
	t_intsect	min;

	min.object = NULL;
	min.t1 = INFINITY;
	min.t2 = INFINITY;
	aux->t1 = -1;
	aux->t2 = -1;
	object_list = data->objects;
	while(object_list)
	{
		if (ray_intersect_object(r, object_list->content, aux))
		{
			if (aux->t1 < min.t1)
			{
				min = *aux;
			}
		}
		object_list = object_list->next;
	}
	*aux = min;
	if (min.object != NULL)
	{
		return (true);
	}
	return (false);
}

static t_color	trace_ray(t_data *data, int i, int j)
{
	t_vec		pixel_center;
	t_ray		cam_ray;
	t_intsect	intsect;

	pixel_center = tpl_add(
		data->frame.offset_pixel,
		tpl_add(
			tpl_multiply(vec(data->frame.ipix_width, 0, 0), i),
			tpl_multiply(vec(0, -data->frame.ipix_height, 0), j)
		)
	);
	cam_ray = ray(data->camera.location, vec_normalize(pixel_center));
	if (intsect_is_found(data, &cam_ray, &intsect))
	{
		return (color(1, 1, 1));
	}
//		return(get_color(data, &cam_ray, &intsect));
	return (color(0, 0, 0));
}

static void	write_image(t_data *data)
{
	size_t				i;
	size_t				j;
	t_color			pixel_color;
	static size_t	n = 0;

	j = -1;
	while (++j < data->img_ptr->height)
	{
		i = -1;
		while (++i < data->img_ptr->width)
		{
			pixel_color = trace_ray(data, i, j);
			write_pixel(pixel_color, data->img_ptr->pixels + n);
			n += 4;
		}
	}
}

void	render(t_data *data)
{
	write_image(data); // ft_memset(data->img_ptr->pixels, 255, data->img_ptr->width * data->img_ptr->height * BPP);
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 09:32:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/11 10:50:22 by muribe-l         ###   ########.fr       */
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

bool	intsect_is_found(t_data *data, t_ray *r, t_intsect *aux)
{
	t_list		*object_list;
	t_intsect	min;

	min.object = NULL;
	min.t = INFINITY;
	aux->t = -1;
	object_list = data->objects;
	while(object_list)
	{
		if (ray_intersect_object(r, object_list->content, aux))
		{
			if (aux->t < min.t)
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
	t_pnt		pixel_center;
	t_ray		r;
	t_ray		new_ray;
	t_intsect	intsect;

	pixel_center = pnt_add(
		data->camera->offset_pixel,
		vec_add(
			tpl_multiply(vec(data->camera->ipix_width, 0, 0), i),
			tpl_multiply(vec(0, -data->camera->ipix_height, 0), j)
		)
	);
	r = ray(pnt(0, 0, 0), vec_normalize(vec_from_to(pnt(0, 0, 0), pixel_center)));
	transform_ray(&r, data->camera->mat, &new_ray);
	if (intsect_is_found(data, &new_ray, &intsect))
	{
		return(get_color(data, &new_ray, &intsect));
	}
	return (color(0, 0, 0));
}

typedef struct {
	t_data	*data;
	int		thread_id;
	int		start_line;
	int		end_line;
	int		n;
	int		width;
}	t_threadData;

void *threadrender(void *d)
{
	t_color			pixel_color;
	t_threadData	*t;

	t = (t_threadData *)d;
	for (size_t j = t->start_line; (int)j <= t->end_line; j++)
	{
		for (size_t i = 0; i < t->data->img_ptr->width; i++)
		{
			pixel_color = trace_ray(t->data, i, j);
			write_pixel(pixel_color, t->data->img_ptr->pixels + t->n); 
			t->n += 4;
		}
		if (t->thread_id == 0)
			printfd(1, "\r%%%d", (int)j * 100 / (int)t->end_line);
	}
	free (t);
	return (NULL);
}

static void	write_image(t_data *data)
{
	long			numThreads = sysconf(_SC_NPROCESSORS_ONLN);
	pthread_t		threads[numThreads];
	int baseLines = data->img_ptr->height / numThreads;
	int extraLines = data->img_ptr->height % numThreads;

	int start_line = 0;
	for (int i = 0; i < numThreads; i++) {
		int end_line = start_line + baseLines - 1;

		if (extraLines > 0) {
			end_line++;
			extraLines--;
		}

		t_threadData *t = malloc(sizeof(t_threadData));
		t->data = data;
		t->thread_id = i;
		t->start_line = start_line;
		t->end_line = end_line;
		t->n = start_line * (data->img_ptr->width * 4);

		pthread_create(&threads[i], NULL, threadrender, t);
		start_line = end_line + 1;
	}

	for (int i = 0; i < numThreads; i++) {
		pthread_join(threads[i], NULL);
	}
}

/* static void	write_image(t_data *data)
{
	size_t			i;
	size_t			j;
	t_color			pixel_color;
	static size_t	n;

	n = 0;
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
		printfd(1, "\r%%%d", (int)j * 100 / (int)data->img_ptr->height);
	}
} */

void	render(t_data *data)
{
	printfd(1, "Rendering image...\n");
	write_image(data); // ft_memset(data->img_ptr->pixels, 255, data->img_ptr->width * data->img_ptr->height * BPP);
	printfd(1, "\nFinished!\n");
	mlx_image_to_window(data->mlx_ptr, data->img_ptr, 0, 0);
	mlx_loop(data->mlx_ptr);
	mlx_terminate(data->mlx_ptr);
}

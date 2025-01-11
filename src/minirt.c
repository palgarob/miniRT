/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/11 16:48:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

static void	check_parameters(int argc, char **argv)
{
	if (argc != 2
		|| ft_strlen(argv[1]) < 4
		|| ft_strcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt")
	)
	{
		ft_dprintf(STDERR_FILENO, WRONG_PARAM);
		exit(1);
	}
}

static void	setup_frame(t_data *data)
{
	int		image_height;
	double	frame_width;
	double	frame_height;

	image_height = IMAGE_WIDTH / ASPECT_RATIO;
	frame_width = tan(data->camera.fov / 2 / DEG2RAD) * 2;
	frame_height = frame_width / ASPECT_RATIO;
	data->frame.ipix_width = frame_width / IMAGE_WIDTH;
	data->frame.ipix_height = frame_height / image_height;
	data->frame.offset_pixel = pnt(
		-frame_width / 2 + data->frame.ipix_width / 2,
		frame_height / 2 - data->frame.ipix_height / 2,
		FOCAL_LENGTH);
}

static void	setup_mlx(t_data *data)
{
	double image_height;

	image_height = IMAGE_WIDTH / ASPECT_RATIO;
	data->mlx_ptr = mlx_init(IMAGE_WIDTH, image_height, "miniRT", false);
	if (!data->mlx_ptr)
	{
		printf(WRONG_PARAM);
		if (data->objects)
			ft_lstclear(&data->objects, free);
		exit(1);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, IMAGE_WIDTH, image_height);
	mlx_loop_hook(data->mlx_ptr, ft_hook, data->mlx_ptr);
}

int	main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) **argv)
{
	t_data		data;

	check_parameters(argc, argv);
	parse(&data, argv[1]);
	setup_frame(&data);
	setup_mlx(&data);
	render(&data);
	if (data.objects)
		ft_lstclear(&data.objects, free);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:28 by pepaloma          #+#    #+#             */
/*   Updated: 2025/03/01 10:50:45 by muribe-l         ###   ########.fr       */
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
		printfd(STDERR_FILENO, WRONG_PARAM);
		exit(1);
	}
}

static void	setup_mlx(t_data *data)
{
	double	image_height;

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

int	main(int argc, char **argv)
{
	t_data		data;

	data.img_ptr = NULL;
	data.mlx_ptr = NULL;
	data.objects = NULL;
	data.camera = NULL;
	data.light = NULL;
	data.ambient = NULL;
	check_parameters(argc, argv);
	parse(&data, argv[1]);
	setup_mlx(&data);
	render(&data);
	free_data(&data);
}

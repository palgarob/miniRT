/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:28 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 14:20:15 by pepaloma         ###   ########.fr       */
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

/* static void	check_parameters(int argc, char **argv)
{
	if (argc != 2
		|| ft_strlen(argv[1]) < 4
		|| ft_strcmp(argv[1] + ft_strlen(argv[1]) - 3, ".rt")
	)
	{
		ft_dprintf(STDERR_FILENO, WRONG_PARAM);
		exit(1);
	}
} */

/* static void	setup_frame(t_data *data)
{
	double	frame_width;
	double	frame_height;
	t_vec3	upper_left_corner;

	frame_width = tan(data->camera.fov / 2 / DEG2RAD) * 2;
	frame_height = frame_width / ASPECT_RATIO;
	data->frame.ipix_width = frame_width / IMAGE_WIDTH;
	data->frame.ipix_height = frame_height / IMAGE_HEIGHT;
	upper_left_corner = vec_add(vec(0, 0, FOCAL_LENGTH),
			vec_add(vec(-frame_width / 2, 0, 0), vec(0, frame_height / 2, 0)));
	data->frame.offset_pixel = vec_add(
			upper_left_corner,
			vec_scale_d(
				vec_add(
					vec(data->frame.ipix_width, 0, 0),
					vec(0, -data->frame.ipix_height, 0)),
				2));
	data->orient_mat.k = data->camera.orientation;
	data->orient_mat.i = vec_cross(data->orient_mat.k, vec(0, 1, 0));
	data->orient_mat.j = vec_cross(data->orient_mat.i, data->orient_mat.k);
} */

static void	setup_mlx(t_data *data)
{
	double image_height;

	image_height = IMAGE_WIDTH / ASPECT_RATIO;
	data->mlx_ptr = mlx_init(IMAGE_WIDTH, image_height, "miniRT", false);
	if (!data->mlx_ptr)
	{
		printf(WRONG_PARAM);
//		if (data->objects)
//			ft_lstclear(&data->objects, free);
		exit(1);
	}
	data->img_ptr = mlx_new_image(data->mlx_ptr, IMAGE_WIDTH, image_height);
	mlx_loop_hook(data->mlx_ptr, ft_hook, data->mlx_ptr);
}

int	main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) **argv)
{
	t_data		data;

//	check_parameters(argc, argv);
//	parse(&data, argv[1]);
//	setup_frame(&data);
	double	a[4][4] = {
		{8, -5, 9, 2},
		{7, 5, 6, 1},
		{-6, 0, 9, 6},
		{-3, 0, -9, -4}
	};
	double	b[4][4] = {
		{9, 3, 0, 9},
		{-5, -2, -6, -3},
		{-4, 9, 6, 4},
		{-7, 6, 6, 2}
	};
	double	ainv[4][4];
	double	binv[4][4];
	if (matrix_inverse(a, ainv))
		matrix4_print(ainv);
	printf("\n");
	if (matrix_inverse(b, binv))
		matrix4_print(binv);
	matrix_multiply(a, b, ainv);
	matrix_multiply(ainv, binv, a);
	matrix4_print(a);
	setup_mlx(&data);
	mlx_loop(data.mlx_ptr);
	mlx_terminate(data.mlx_ptr);
//	render(&data);
//	if (data.objects)
//		ft_lstclear(&data.objects, free);
}

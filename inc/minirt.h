/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:07:19 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:21:18 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h> // bool
# include <math.h> // sqrt pow
# include <stdlib.h> // free malloc exit
# include <unistd.h> // STDERR_FILENO close read write
# include <stdio.h> // printf perror
# include <fcntl.h> // open
# include <string.h> // strerror

# include "MLX42.h"
# include "libft.h"

/* PREPROCESSOR PARAMETERS                                                    */
# define ASPECT_RATIO (16.0 / 9.0)
# define IMAGE_WIDTH 960
# define FOCAL_LENGTH 1.0
# define BPP sizeof(int32_t)

/* ERROR MESSAGES                                                             */
# define BAD_OPEN "Error\nError when opening file\n"
# define WRONG_PARAM "Error\nPass only one *.rt file as parameter\n"
# define BAD_MLX_INIT "Error\nThe mlx_init returned NULL\n"
# define BAD_ELEM_FORMAT "Error\nAn element of the scene doesn't have the \
right format\n"

/* RAY                                                                        */
typedef struct s_ray
{
	t_pnt	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_object t_object;
typedef struct s_intersection
{
	t_object	*object;
	double	t1;
	double	t2;
	t_vec	normal;
} t_intsect;

t_ray	ray(t_pnt origin, t_vec direction);
t_pnt	ray_position(t_ray *ray, double t);
bool	ray_intersect_object(t_ray *r, t_object *o, t_intsect *x);
void	find_sp_intersection(t_ray *r, t_object *o, t_intsect *h);
void	transform_ray(t_ray *ray, double mat[4][4], t_ray *new_ray);

/* MAIN PART                                                                  */

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CAMERA,
	LIGHT
}	t_obj_type;

typedef struct s_camera
{
	double	mat[4][4];
	double	ipix_width;
	double	ipix_height;
	t_pnt	offset_pixel;
}	t_camera;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}	t_ambient;

typedef struct s_light
{
	double	mat[4][4];
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_object
{
	t_obj_type	type;
	t_color		color;
	double		mat[4][4];
}	t_object;

typedef struct s_data
{
	mlx_image_t	*img_ptr;
	mlx_t		*mlx_ptr;
	t_list		*objects;
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
}	t_data;

void	parse(t_data *data, char *filename);
void	render(t_data *data);
t_color	get_color(t_data *data, t_ray *ray, t_intsect *intsect);
void	free_data(t_data *data);
void	setup_frame(t_data *data, double fov);
int	create_object(t_data *data, char **info_array, t_obj_type type);
void	transformation(double mat[4][4], t_transformation *t, t_obj_type type);

#endif

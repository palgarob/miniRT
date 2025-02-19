/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:07:19 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/19 16:58:58 by muribe-l         ###   ########.fr       */
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
# include <pthread.h> // Threads
# include <sys/sysinfo.h> //Cores

# include "MLX42.h"
# include "libft.h"

/* PREPROCESSOR PARAMETERS                                                    */
# define ASPECT_RATIO 1.777777778
# define IMAGE_WIDTH 1020
# define FOCAL_LENGTH 1.0
# define BPP 4

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

typedef struct s_object	t_object;
typedef struct s_intersection
{
	t_object	*object;
	double		t;
	t_vec		normal;
}	t_intsect;

t_ray	ray(t_pnt origin, t_vec direction);
t_pnt	ray_position(t_ray *ray, double t);
bool	ray_intersect_object(t_ray *r, t_object *o, t_intsect *x);
bool	sp_is_intersected(t_ray *r, double t[2]);
bool	pl_is_intersected(t_ray *r, double t[2]);
bool	cy_is_intersected(t_ray *r, double t[2]);
void	transform_ray(t_ray *ray, double mat[4][4], t_ray *new_ray);

/* CREATE ELEMENTS                                                            */
typedef struct s_data	t_data;
typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_obj_type;

typedef struct s_camera
{
	double	mat[4][4];
	t_pnt	location;
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
	t_pnt	location;
	double	brightness;
	t_color	color;
}	t_light;

typedef struct s_material
{
	t_color	c;
	double	a_ratio;
	t_color	a_color;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

typedef struct s_object
{
	t_obj_type	type;
	t_color		color;
	t_vec		orientation;
	double		mat[4][4];
	t_material	teri;
}	t_object;

int		create_sphere(t_data *data, char **line_split);
int		create_cylinder(t_data *data, char **line_split);
int		create_plane(t_data *data, char **line_split);
int		create_light(t_data *data, char **line_split);
int		create_ambient(t_data *data, char **line_split);
int		create_camera(t_data *data, char **line_split);
t_material	material(t_color c, double diffuse, t_ambient *ambient, double shininess, double specular);

/* RENDER                                                                     */
void	render(t_data *data);
t_color	get_color(t_data *data, t_ray *r, t_intsect *intsect);
t_vec	reflect(t_vec normal, t_vec in);

/* DATA STRUCTURE                                                             */

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
void	free_data(t_data *data);

#endif

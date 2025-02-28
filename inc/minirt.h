/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:07:19 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 08:05:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h> // printf perror
# include <fcntl.h> // open
# include <string.h> // strerror

# include "MLX42.h"
# include "libft.h"

/* PREPROCESSOR PARAMETERS                                                    */
# define ASPECT_RATIO 1.7777777
# define IMAGE_WIDTH 480
# define FOCAL_LENGTH 1.0

/* ERROR MESSAGES                                                             */
# define BAD_OPEN "Error\nError when opening file\n"
# define WRONG_PARAM "Error\nPass only one *.rt file as parameter\n"
# define BAD_MLX_INIT "Error\nThe mlx_init returned NULL\n"
# define BAD_ELEM_FORMAT "Error\nAn element of the scene doesn't have the \
right format\n"

/* COLOR                                                                      */
typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	color(double r, double g, double b);
t_color	color_blend(t_color a, t_color b);
t_color	color_mul(t_color c, double fpnd);
t_color	color_add(t_color a, t_color b);
t_color	color_sub(t_color a, t_color b);
bool	is_rgb(t_color *dst, char *src);

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
	bool		interior_hit;
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

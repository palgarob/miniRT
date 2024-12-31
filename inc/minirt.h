/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:07:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/31 21:22:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h> // bool
# include <math.h> // sqrt pow
# include <stdlib.h> // free malloc
# include <unistd.h> // STDERR_FILENO
# include <stdio.h> // printf

# include "MLX42.h"

/* PREPROCESSOR PARAMETERS                                                    */
# define EPSILON 0.00001
# define ASPECT_RATIO (16.0 / 9.0)
# define IMAGE_WIDTH 960
# define FOCAL_LENGTH 1.0

/* ERROR MESSAGES                                                             */
# define WRONG_PARAM "Error\nPass only one *.rt file as parameter\n"
# define BAD_MLX_INIT "Error\nThe mlx_init returned NULL\n"
# define INVALID_MATRIX_SIZE "Error \nDon't compare matrixes other than \
2x2, 3x3, 4x4\n"

/* UTILS                                                                      */
typedef enum e_comp_result
{
	EQUAL,
	A_LESST_B,
	A_GREAT_B
}	t_comp;

t_comp			fpn_compare(double a, double b);
double			deg2rad(double deg);

/* TUPLES                                                                     */
struct s_tpl
{
	double	x;
	double	y;
	double	z;
	double	w;
};

bool			tpl_equal(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_negate(struct s_tpl tpl);
struct s_tpl	tpl_add(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_sub(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_multiply(struct s_tpl, double scalar);
struct s_tpl	tpl_divide(struct s_tpl, double scalar);
struct s_tpl	tpl(double x, double y, double z, double w);
struct s_tpl	tpl_multiply_matrix(double mat[4][4], struct s_tpl tpl);

/* POINTS AND VECTORS                                                         */
typedef struct s_tpl t_pnt, t_vec;
t_pnt			pnt(double x, double y, double z);
t_pnt			pnt_add(t_pnt point, t_vec vector);
t_pnt			pnt_sub(t_pnt point, t_vec vector);
t_vec			vec(double x, double y, double z);
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_from_to(t_pnt from, t_pnt to);
double			vec_len(t_vec vector);
t_vec			vec_normalize(t_vec vector);
double			vec_dot(t_vec a, t_vec b);
t_vec			vec_cross(t_vec a, t_vec b);

/* COLOR                                                                      */
typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	color(double r, double g, double b);
t_color	color_blend(t_color a, t_color b);

/* MATRIX                                                                     */
bool	matrix_is_equal(double a[4][4], double b[4][4], size_t size);
void	matrix_multiply(double a[4][4], double b[4][4], double result[4][4]);
void	matrix_transpose(double **mat);
void	matrix_cpy(double src[4][4], double cpy[4][4]);
double	matrix2_det(double mat2[2][2]);
void	submatrix4(double mat4[4][4], double mat3[3][3], int row, int column);
void	submatrix3(double mat3[3][3], double mat2[2][2], int row, int column);
double	matrix3_minor(double mat3[3][3], int row, int column);
double	matrix4_minor(double mat4[4][4], int row, int column);
double	matrix3_cofactor(double mat3[3][3], int row, int column);
double	matrix4_cofactor(double mat4[4][4], int row, int column);
double	matrix3_det(double mat3[3][3]);
double	matrix4_det(double mat4[4][4]);
bool	matrix_inverse(double mat4[4][4], double inv[4][4]);
void	matrix4_print(double mat4[4][4]);

/* TRANSFORMATIONS                                                            */
void	translation(double mat[4][4], double x, double y, double z);
void	scaling(double mat[4][4], double x, double y, double z);
void	rotation_x(double mat[4][4], double degrees);
void	rotation_y(double mat[4][4], double degrees);
void	rotation_z(double mat[4][4], double degrees);
t_pnt	transform(double mat[4][4], t_pnt point);
t_pnt	transform_inv(double mat[4][4], t_pnt point);

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
} t_intersection;

t_ray	ray(t_pnt origin, t_vec direction);
t_pnt	ray_position(t_ray *ray, double t);
bool	ray_intersect(t_ray *r, t_object *o, t_intersection *x);

/* ORDENAR                                                                    */

void	find_sp_intersection(t_ray *r, t_object *o, t_intersection *h);
void	transform_ray(t_ray *ray, double mat[4][4], t_ray *new_ray);
void	set_transformation(double mat[4][4], t_object *o);

typedef struct s_frame
{
	double	ipix_width;
	double	ipix_height;
	t_pnt	offset_pixel;
}	t_frame;

typedef struct s_camera
{
	t_pnt		location;
	t_vec		orientation;
	int			fov;
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

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_obj_type;

typedef struct s_object
{
	double		transformation[4][4];
	t_obj_type		type;
	t_pnt			location;
	t_vec			orientation;
	t_color			color;
	double			diameter;
	double			height;
}	t_object;

t_object	*sphere(t_pnt *location,
					t_vec *orientation,
					t_color *color,
					double diameter);

// Main part
typedef struct s_data
{
	mlx_image_t	*img_ptr;
	mlx_t		*mlx_ptr;
}	t_data;

#endif

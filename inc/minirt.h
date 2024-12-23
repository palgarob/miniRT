/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:07:19 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 22:39:34 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdbool.h> // bool
# include <math.h> // sqrt pow
# include <stdlib.h> // free malloc
# include <unistd.h> //STDERR_FILENO

# include "MLX42.h"

# define EPSILON 0.00001
# define ASPECT_RATIO (16.0 / 9.0)
# define IMAGE_WIDTH 960
# define FOCAL_LENGTH 1.0

// Error messages
# define WRONG_PARAM "Error\nPass only one *.rt file as parameter"
# define BAD_MLX_INIT "Error\nThe mlx_init returned NULL"

typedef enum e_comp_result
{
	EQUAL,
	A_LESST_B,
	A_GREAT_B
}	t_comp;

t_comp			fpn_compare(double a, double b);

// tuples
typedef struct s_tpl
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

// points and vectors
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

// color
typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

t_color	color(double r, double g, double b);
t_color	color_blend(t_color a, t_color b);

#endif

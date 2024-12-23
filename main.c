/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:28 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 19:00:51 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#define EPSILON 0.00001

typedef enum e_comp_result
{
	EQUAL,
	A_LESST_B,
	A_GREAT_B
}	t_comp;

typedef struct s_tpl
{
	double	x;
	double	y;
	double	z;
	double	w;
} t_pnt, t_vec;

t_comp			fpn_compare(double a, double b);

bool			tpl_equal(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_negate(struct s_tpl tpl);
struct s_tpl	tpl_add(struct s_tpl a, struct s_tpl b);
struct s_tpl	tpl_sub(struct s_tpl a, struct s_tpl b);

t_pnt			pnt(double x, double y, double z);
t_pnt			pnt_add(t_pnt point, t_vec vector);
t_pnt			pnt_sub(t_pnt point, t_vec vector);

t_pnt			vec(double x, double y, double z);
t_vec			vec_add(t_vec a, t_vec b);
t_vec			vec_sub(t_vec a, t_vec b);
t_vec			vec_from_to(t_pnt from, t_pnt to);


//code

/*
 * @brief Compares two floating-point numbers.
 *
 * This function compares two floating-point numbers, `a` and `b`, and returns
 * an enumeration value indicating whether `a` is equal to, less than, or greater than `b`.
 * The comparison takes into account a small epsilon value to handle floating-point precision issues.
 *
 * @param a The first floating-point number to compare.
 * @param b The second floating-point number to compare.
 * @return A t_comp enumeration value:
 *         - EQUAL if the numbers are approximately equal (difference is less than EPSILON).
 *         - A_LESST_B if `a` is less than `b`.
 *         - A_GREAT_B if `a` is greater than `b`.
 */
t_comp	fpn_compare(double a, double b)
{
	if (a - b < EPSILON)
		return (EQUAL);
	if (a - b < 0)
		return (A_LESST_B);
	else
		return (A_GREAT_B);
}

bool	tpl_equal(struct s_tpl a, struct s_tpl b)
{
	if (
		fpn_compare(a.x, b.x) || fpn_compare(a.y, b.y)
		|| fpn_compare(a.z, b.z) || fpn_compare(a.w, b.w)
	)
		return (false);
	return (true);
}

struct s_tpl	tpl_negate(struct s_tpl tpl)
{
	tpl.x = -tpl.x;
	tpl.y = -tpl.y;
	tpl.z = -tpl.z;
	tpl.w = -tpl.w;
	return (tpl);
}

struct s_tpl	tpl_add(struct s_tpl a, struct s_tpl b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

struct s_tpl	tpl_sub(struct s_tpl a, struct s_tpl b)
{
	return (tpl_add(a, tpl_negate(b)));
}

t_pnt	pnt(double x, double y, double z)
{
	t_pnt	point;
	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
}

t_pnt	pnt_add(t_pnt point, t_vec vector)
{
	return (tpl_add(point, vector));
}

t_pnt	pnt_sub(t_pnt point, t_vec vector)
{
	return (pnt_add(point, tpl_negate(vector)));
}

t_vec	vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

t_vec	vec(double x, double y, double z)
{
	t_pnt	vector;
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0.0;
	return (vector);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	return (tpl_sub(a, b));
}

/*
 * @return vector from one point to another
 */
t_vec	vec_from_to(t_pnt from, t_pnt to)
{
	return (tpl_sub(to, from));
}

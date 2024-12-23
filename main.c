/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:19:28 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 17:35:51 by pepaloma         ###   ########.fr       */
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

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
} t_pnt, t_vec;

t_pnt	vec(double x, double y, double z);
t_pnt	point(double x, double y, double z);
t_comp	fpn_compare(double a, double b);
bool	equal_tuple(struct s_tuple a, struct s_tuple b);
t_pnt	point_translate(t_pnt point, t_vec vector);
t_vec	vec_add(t_vec point, t_vec vector);

//code

bool	tuple_equal(struct s_tuple a, struct s_tuple b)
{
	if (
		fpn_compare(a.x, b.x) || fpn_compare(a.y, b.y)
		|| fpn_compare(a.z, b.z) || fpn_compare(a.w, b.w)
	)
		return (false);
	return (true);
}

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

t_pnt	point_translate(t_pnt point, t_vec vector)
{
	point.x += vector.x;
	point.y += vector.y;
	point.z += vector.z;
	point.w += vector.w;
	return (point);
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

t_pnt	point(double x, double y, double z)
{
	t_pnt	point;
	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1.0;
	return (point);
}

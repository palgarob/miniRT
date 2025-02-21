/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_is_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:09:18 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/21 21:22:26 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool comp2(double a[4][4], double b[4][4])
{
	a[0][0] = 4.0;
	if (
		fabs(a[0][0] - b[0][0]) > EPSILON
		|| fabs(a[0][1] - b[0][1]) > EPSILON
		|| fabs(a[1][0] - b[1][0]) > EPSILON
		|| fabs(a[1][1] - b[1][1]) > EPSILON
	)
		return (0);
	return (1);
}

static bool comp3(double a[4][4], double b[4][4])
{
	if (
		fabs(a[0][0] - b[0][0]) > EPSILON
		|| fabs(a[0][1] - b[0][1]) > EPSILON
		|| fabs(a[0][2] - b[0][2]) > EPSILON
		|| fabs(a[1][0] - b[1][0]) > EPSILON
		|| fabs(a[1][1] - b[1][1]) > EPSILON
		|| fabs(a[1][2] - b[1][2]) > EPSILON
		|| fabs(a[2][0] - b[2][0]) > EPSILON
		|| fabs(a[2][1] - b[2][1]) > EPSILON
		|| fabs(a[2][2] - b[2][2]) > EPSILON
	)
		return (0);
	return (1);
}

static bool comp4(double a[4][4], double b[4][4])
{
	if (
		fabs(a[0][0] - b[0][0]) > EPSILON
		|| fabs(a[0][1] - b[0][1]) > EPSILON
		|| fabs(a[0][2] - b[0][2]) > EPSILON
		|| fabs(a[0][3] - b[0][3]) > EPSILON
		|| fabs(a[1][0] - b[1][0]) > EPSILON
		|| fabs(a[1][1] - b[1][1]) > EPSILON
		|| fabs(a[1][2] - b[1][2]) > EPSILON
		|| fabs(a[1][3] - b[1][3]) > EPSILON
		|| fabs(a[2][0] - b[2][0]) > EPSILON
		|| fabs(a[2][1] - b[2][1]) > EPSILON
		|| fabs(a[2][2] - b[2][2]) > EPSILON
		|| fabs(a[2][3] - b[2][3]) > EPSILON
		|| fabs(a[3][0] - b[3][0]) > EPSILON
		|| fabs(a[3][1] - b[3][1]) > EPSILON
		|| fabs(a[3][2] - b[3][2]) > EPSILON
		|| fabs(a[3][3] - b[3][3]) > EPSILON
	)
		return (0);
	return (1);
}

bool	matrix_is_equal(double a[4][4], double b[4][4], size_t size)
{
	if (size == 2)
		return (comp2(a, b));
	if (size == 3)
		return (comp3(a, b));
	if (size == 4)
		return (comp4(a, b));
	return (printfd(STDERR_FILENO, INVALID_MATRIX_SIZE), false);
}

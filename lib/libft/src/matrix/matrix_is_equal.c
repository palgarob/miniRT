/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_is_equal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:09:18 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:10:57 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool comp2(double a[4][4], double b[4][4])
{
	a[0][0] = 4.0;
	if (
		fpn_compare(a[0][0], b[0][0]) != EQUAL
		|| fpn_compare(a[0][1], b[0][1]) != EQUAL
		|| fpn_compare(a[1][0], b[1][0]) != EQUAL
		|| fpn_compare(a[1][1], b[1][1]) != EQUAL
	)
		return (0);
	return (1);
}

static bool comp3(double a[4][4], double b[4][4])
{
	if (
		fpn_compare(a[0][0], b[0][0]) != EQUAL
		|| fpn_compare(a[0][1], b[0][1]) != EQUAL
		|| fpn_compare(a[0][2], b[0][2]) != EQUAL
		|| fpn_compare(a[1][0], b[1][0]) != EQUAL
		|| fpn_compare(a[1][1], b[1][1]) != EQUAL
		|| fpn_compare(a[1][2], b[1][2]) != EQUAL
		|| fpn_compare(a[2][0], b[2][0]) != EQUAL
		|| fpn_compare(a[2][1], b[2][1]) != EQUAL
		|| fpn_compare(a[2][2], b[2][2]) != EQUAL
	)
		return (0);
	return (1);
}

static bool comp4(double a[4][4], double b[4][4])
{
	if (
		fpn_compare(a[0][0], b[0][0]) != EQUAL
		|| fpn_compare(a[0][1], b[0][1]) != EQUAL
		|| fpn_compare(a[0][2], b[0][2]) != EQUAL
		|| fpn_compare(a[0][3], b[0][3]) != EQUAL
		|| fpn_compare(a[1][0], b[1][0]) != EQUAL
		|| fpn_compare(a[1][1], b[1][1]) != EQUAL
		|| fpn_compare(a[1][2], b[1][2]) != EQUAL
		|| fpn_compare(a[1][3], b[1][3]) != EQUAL
		|| fpn_compare(a[2][0], b[2][0]) != EQUAL
		|| fpn_compare(a[2][1], b[2][1]) != EQUAL
		|| fpn_compare(a[2][2], b[2][2]) != EQUAL
		|| fpn_compare(a[2][3], b[2][3]) != EQUAL
		|| fpn_compare(a[3][0], b[3][0]) != EQUAL
		|| fpn_compare(a[3][1], b[3][1]) != EQUAL
		|| fpn_compare(a[3][2], b[3][2]) != EQUAL
		|| fpn_compare(a[3][3], b[3][3]) != EQUAL
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

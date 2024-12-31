/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpn_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:16:40 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:17:29 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

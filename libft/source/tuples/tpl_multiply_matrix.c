/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_multiply_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:18:02 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 21:24:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_tpl	tpl_multiply_matrix(double mat[4][4], struct s_tpl tuple)
{
	struct s_tpl result;

	result.x = vec_dot(tuple, tpl(mat[0][0], mat[0][1], mat[0][2], mat[0][3]));
	result.y = vec_dot(tuple, tpl(mat[1][0], mat[1][1], mat[1][2], mat[1][3]));
	result.z = vec_dot(tuple, tpl(mat[2][0], mat[2][1], mat[2][2], mat[2][3]));
	result.w = vec_dot(tuple, tpl(mat[3][0], mat[3][1], mat[3][2], mat[3][3]));
	return (result);
}

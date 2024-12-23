/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_matrix_multiply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:18:02 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 00:34:20 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_tpl	tpl_multiply_matrix(double **mat, t_vec vector)
{
	struct s_tpl tuple;

	tuple.x = vec_dot(vector, tpl(mat[0][0], mat[0][1], mat[0][2], mat[0][3]));
	tuple.y = vec_dot(vector, tpl(mat[1][0], mat[1][1], mat[1][2], mat[1][3]));
	tuple.z = vec_dot(vector, tpl(mat[2][0], mat[2][1], mat[2][2], mat[2][3]));
	tuple.w = vec_dot(vector, tpl(mat[3][0], mat[3][1], mat[3][2], mat[3][3]));
	return (tuple);
}

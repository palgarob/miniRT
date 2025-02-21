/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_inv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:41:07 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 16:32:27 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pnt	transform_inv(double mat[4][4], t_pnt point)
{
	double	inv[4][4];

	matrix_inverse(mat, inv);
	return (tpl_multiply_matrix(inv, point));
}

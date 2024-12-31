/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_inv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:41:07 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/29 18:53:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pnt	transform_inv(double mat[4][4], t_pnt point)
{
	double	inv[4][4];

	matrix_inverse(mat, inv);
	return (tpl_multiply_matrix(inv, point));
}

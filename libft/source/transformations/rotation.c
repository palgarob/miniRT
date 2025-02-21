/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 21:44:16 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/06 19:55:18 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotation(double mat[4][4], t_vec *v)
{
	t_vec	aux;
	t_vec	up;

	if ((fpn_compare(v->x, 0) == EQUAL && fpn_compare(v->y, 1) == EQUAL && fpn_compare(v->z, 0) == EQUAL)
	|| (fpn_compare(v->x, 0) == EQUAL && fpn_compare(v->y, -1) == EQUAL && fpn_compare(v->z, 0) == EQUAL))
	{
		up = vec(0, 0, -1);
		aux = vec_cross(up, *v);
		mat[0][0] = aux.x;
		mat[0][1] = aux.y;
		mat[0][2] = aux.z;
		mat[0][3] = 0;
		mat[1][0] = 0;
		mat[1][1] = 0;
		mat[1][2] = -1;
		mat[1][3] = 0;
	}
	else
	{
		up = vec(0, 1, 0);
		aux = vec_cross(up, *v);
		mat[0][0] = aux.x;
		mat[0][1] = aux.y;
		mat[0][2] = aux.z;
		mat[0][3] = 0;
		aux = vec_cross(*v, aux);
		mat[1][0] = aux.x;
		mat[1][1] = aux.y;
		mat[1][2] = aux.z;
		mat[1][3] = 0;
	}
	mat[2][0] = v->x;
	mat[2][1] = v->y;
	mat[2][2] = v->z;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transformation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:59:40 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/31 21:05:10 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transformation(double mat[4][4], t_object *o)
{
	if (!mat)
	{
		o->transformation[0][0] = 1;
		o->transformation[0][1] = 0;
		o->transformation[0][2] = 0;
		o->transformation[0][3] = 0;
		o->transformation[1][0] = 0;
		o->transformation[1][1] = 1;
		o->transformation[1][2] = 0;
		o->transformation[1][3] = 0;
		o->transformation[2][0] = 0;
		o->transformation[2][1] = 0;
		o->transformation[2][2] = 1;
		o->transformation[2][3] = 0;
		o->transformation[3][0] = 0;
		o->transformation[3][1] = 0;
		o->transformation[3][2] = 0;
		o->transformation[3][3] = 1;
	}
	else
		matrix_cpy(mat, o->transformation);
}

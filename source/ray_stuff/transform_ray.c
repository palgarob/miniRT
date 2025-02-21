/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:46:47 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/31 20:55:06 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_ray(t_ray *ray, double mat[4][4], t_ray *new_ray)
{
	new_ray->direction = tpl_multiply_matrix(mat, ray->direction);
	new_ray->origin = tpl_multiply_matrix(mat, ray->origin);
}

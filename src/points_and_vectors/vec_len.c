/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:05 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:11:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_len(t_vec vector)
{
	return (
		sqrt(
			pow(vector.x, 2)
			+ pow(vector.y, 2)
			+ pow(vector.z, 2)
			+ pow(vector.w, 2)
		)
	);
}

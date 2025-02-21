/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:05 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:47:26 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

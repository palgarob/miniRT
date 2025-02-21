/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:30 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:47:30 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	vec_normalize(t_vec vector)
{
	double	len;

	len = vec_len(vector);
	vector.x /= len;
	vector.y /= len;
	vector.z /= len;
	vector.w /= len;
	return (vector);
}

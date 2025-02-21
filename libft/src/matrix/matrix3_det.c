/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3_det.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 10:35:20 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 16:38:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	matrix3_det(double mat3[3][3])
{
	return (
		mat3[0][0] * matrix3_cofactor(mat3, 0, 0)
		+ mat3[0][1] * matrix3_cofactor(mat3, 0, 1)
		+ mat3[0][2] * matrix3_cofactor(mat3, 0, 2)
	);
}

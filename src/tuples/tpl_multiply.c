/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_multiply.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:04:10 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:04:21 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_tpl	tpl_multiply(struct s_tpl tuple, double scalar)
{
	tuple.x *= scalar;
	tuple.y *= scalar;
	tuple.z *= scalar;
	tuple.w *= scalar;
	return (tuple);
}

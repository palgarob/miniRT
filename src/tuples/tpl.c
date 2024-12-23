/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:28:25 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 00:29:53 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_tpl tpl(double x, double y, double z, double w)
{
	struct s_tpl	tuple;
	
	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

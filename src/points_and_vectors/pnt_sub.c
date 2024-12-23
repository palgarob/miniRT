/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:08:07 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:08:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pnt	pnt_sub(t_pnt point, t_vec vector)
{
	return (pnt_add(point, tpl_negate(vector)));
}

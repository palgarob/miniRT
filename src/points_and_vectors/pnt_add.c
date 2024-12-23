/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pnt_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:07:44 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:07:59 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pnt	pnt_add(t_pnt point, t_vec vector)
{
	return (tpl_add(point, vector));
}

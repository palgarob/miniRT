/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plt_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:02:52 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:03:11 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_tpl	tpl_add(struct s_tpl a, struct s_tpl b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

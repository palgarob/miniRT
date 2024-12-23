/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_equal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:00:40 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:02:05 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	tpl_equal(struct s_tpl a, struct s_tpl b)
{
	if (
		fpn_compare(a.x, b.x) || fpn_compare(a.y, b.y)
		|| fpn_compare(a.z, b.z) || fpn_compare(a.w, b.w)
	)
		return (false);
	return (true);
}

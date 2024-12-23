/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_negate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:02:23 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:02:41 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_tpl	tpl_negate(struct s_tpl tpl)
{
	tpl.x = -tpl.x;
	tpl.y = -tpl.y;
	tpl.z = -tpl.z;
	tpl.w = -tpl.w;
	return (tpl);
}

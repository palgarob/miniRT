/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:03:38 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/23 21:03:58 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

struct s_tpl	tpl_sub(struct s_tpl a, struct s_tpl b)
{
	return (tpl_add(a, tpl_negate(b)));
}

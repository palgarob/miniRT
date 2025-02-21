/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpl_divide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:04:32 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/14 21:24:15 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

struct s_tpl	tpl_divide(struct s_tpl tuple, double scalar)
{
	tuple.x /= scalar;
	tuple.y /= scalar;
	tuple.z /= scalar;
	tuple.w /= scalar;
	return (tuple);
}

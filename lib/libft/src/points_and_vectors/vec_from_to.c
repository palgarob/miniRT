/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:10:37 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:47:23 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @return vector from one point to another
 */
t_vec	vec_from_to(t_pnt from, t_pnt to)
{
	return (tpl_sub(to, from));
}

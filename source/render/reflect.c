/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:37:39 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 17:42:18 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	reflect(t_vec normal, t_vec in)
{
	return (
		vec_sub(in, tpl_multiply(normal, 2 * vec_dot(in, normal)))
	);
}

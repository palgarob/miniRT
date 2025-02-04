/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:12:08 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/04 01:15:38 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	material(t_color c, double diffuse, t_ambient *ambient, double shininess, double specular)
{
	t_material	teri;

	teri.c = c;
	teri.a_color = ambient->color;
	teri.a_ratio = ambient->ratio;
	teri.specular = specular;
	teri.diffuse = diffuse;
	teri.shininess = shininess;
	return (teri);
}

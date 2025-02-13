/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:12:08 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/13 17:58:12 by muribe-l         ###   ########.fr       */
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

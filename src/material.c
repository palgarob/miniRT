/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:12:08 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/19 17:13:47 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	material(t_color c, double diffuse, double ambient, double shininess, double specular)
{
	t_material	teri;

	teri.ambient = ambient;
	teri.specular = specular;
	teri.diffuse = diffuse;
	teri.color = c;
	teri.shininess = shininess;
	return (teri);
}

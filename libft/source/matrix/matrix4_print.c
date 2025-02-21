/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:17:56 by pepaloma          #+#    #+#             */
/*   Updated: 2024/12/24 13:33:13 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	matrix4_print(double mat4[4][4])
{
	int i = 0;
	while (i < 4)
	{
		printf("| ");
		int j = 0;
		while (j < 4)
		{
			printf("%g\t", mat4[i][j]);
			j++;
		}
		printf("|\n");
		i++;
	}
}

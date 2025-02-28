/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:17:56 by pepaloma          #+#    #+#             */
/*   Updated: 2025/02/28 11:23:20 by muribe-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	matrix4_print(double mat4[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		printfd(1, "| ");
		j = 0;
		while (j < 4)
		{
			printfd(1, "%g\t", mat4[i][j]);
			j++;
		}
		printfd(1, "|\n");
		i++;
	}
}

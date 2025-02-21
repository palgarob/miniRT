/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:27:13 by pepaloma          #+#    #+#             */
/*   Updated: 2024/04/21 22:21:12 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	splitfree(char **split)
{
	char	**aux;

	aux = split;
	while (*split)
		free(*(split++));
	free(aux);
}

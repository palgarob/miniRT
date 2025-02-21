/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:07:16 by pepaloma          #+#    #+#             */
/*   Updated: 2024/03/20 13:12:08 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**splitlast(char **split)
{
	if (!*split)
		return (NULL);
	while (*(split + 1))
		split++;
	return (split);
}

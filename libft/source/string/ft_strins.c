/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:54:02 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:13:34 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strins(char **str_ptr, int snip_l, int snip_r, char *str_insert)
{
	char	*left;
	char	*right;

	left = ft_substr(*str_ptr, 0, snip_l);
	if (!left)
		return (1);
	right = ft_substr(*str_ptr, snip_r, ft_strlen(&(*str_ptr)[snip_r]));
	if (!right)
		return (free(left), 1);
	free(*str_ptr);
	*str_ptr = ft_strjoin(left, str_insert);
	free(left);
	if (!*str_ptr)
		return (1);
	*str_ptr = ft_strjoin_gnl(*str_ptr, right);
	free(right);
	if (!*str_ptr)
		return (1);
	return (0);
}

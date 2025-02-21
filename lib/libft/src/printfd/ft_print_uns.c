/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 13:20:05 by pedropalomare     #+#    #+#             */
/*   Updated: 2025/01/13 23:48:24 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_dec(int fd, unsigned int n)
{
	if (n >= 10)
		write_dec(fd, n / 10);
	write(fd, &DECIMAL[n % 10], 1);
}

int	ft_print_uns(int fd, unsigned int n)
{
	int	i;

	write_dec(fd, n);
	i = 0;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

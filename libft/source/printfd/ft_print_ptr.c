/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:15:03 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:48:16 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_hex_ptr(int fd, unsigned long long n)
{
	if (n >= 16)
		write_hex_ptr(fd, n / 16);
	write(fd, &HEXADECIMAL_LO[n % 16], 1);
}

int	ft_print_ptr(int fd, void *ptr)
{
	unsigned long long	p;
	int					i;

	i = 0;
	p = (unsigned long long)ptr;
	write(fd, "0x", 2);
	write_hex_ptr(fd, p);
	while (p / 16)
	{
		p /= 16;
		i++;
	}
	return (i + 3);
}

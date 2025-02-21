/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:04:50 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/13 23:48:13 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_hex_up(int fd, unsigned int n)
{
	if (n >= 16)
		write_hex_up(fd, n / 16);
	write(fd, &HEXADECIMAL_UP[n % 16], 1);
}

static void	write_hex_lo(int fd, unsigned int n)
{
	if (n >= 16)
		write_hex_lo(fd, n / 16);
	write(fd, &HEXADECIMAL_LO[n % 16], 1);
}

int	ft_print_hex(int fd, unsigned int n, int lcase)
{
	int	i;

	i = 0;
	if (lcase)
		write_hex_up(fd, n);
	else
		write_hex_lo(fd, n);
	while (n / 16)
	{
		i++;
		n /= 16;
	}
	return (i + 1);
}

/* int	main(void)
{
	int	n = 256;

	printf("\n%d\n", ft_print_hex(n));
	return (0);
} */

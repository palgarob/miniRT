/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:03:27 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/15 01:10:17 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nb(char *s, int n, size_t len)
{
	int	nb;

	if (n == -2147483648)
	{
		ft_strlcpy(s, "-2147483648", 12);
		return ;
	}
	if (!n)
	{
		s[0] = '0';
		return ;
	}
	nb = n;
	if (n < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	while (nb)
	{
		s[--len] = (nb % 10) + '0';
		nb /= 10;
	}
}

static size_t	nbrlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	len;

	len = nbrlen(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	s[len] = 0;
	write_nb(s, n, len);
	return (s);
}

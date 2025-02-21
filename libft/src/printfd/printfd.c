/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:10:25 by pepaloma          #+#    #+#             */
/*   Updated: 2025/01/16 08:44:08 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_format(int fd, const char c, va_list *ptr)
{
	if (c == 'c')
		return (ft_print_char(fd, va_arg(*ptr, int)));
	if (c == 's')
		return (ft_print_str(fd, va_arg(*ptr, char *)));
	if (c == 'x')
		return (ft_print_hex(fd, va_arg(*ptr, int), 0));
	if (c == 'X')
		return (ft_print_hex(fd, va_arg(*ptr, int), 1));
	if (c == 'p')
		return (ft_print_ptr(fd, va_arg(*ptr, void *)));
	if (c == 'd' || c == 'i')
		return (ft_print_dec(fd, va_arg(*ptr, int)));
	if (c == 'u')
		return (ft_print_uns(fd, va_arg(*ptr, unsigned int)));
	if (c == '%')
		return (write(fd, "\%", 1));
	else
		return (write(fd, "UNSPECIFIED FORMAT", 18));
}

int	printfd(int fd, char const *format, ...)
{
	va_list	ptr;
	int		n;

	n = 0;
	va_start(ptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			n += write_format(fd, *(format + 1), &ptr);
			format++;
		}
		else
			n += write(1, format, 1);
		format++;
	}
	va_end(ptr);
	return (n);
}

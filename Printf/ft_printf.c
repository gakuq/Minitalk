/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:10:57 by mmaterna          #+#    #+#             */
/*   Updated: 2025/01/30 09:29:19 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *s, int i)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s, 1);
		i++;
		s++;
	}
	return (i);
}

int	ft_printdecimal(int d, int i)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		i = i + 11;
	}
	else if (d < 0)
	{
		i = ft_write('-', i);
		i = ft_printdecimal(-d, i);
	}
	else if (d >= 0 && d < 10)
		i = ft_write(d + '0', i);
	else
	{
		i = ft_printdecimal(d / 10, i);
		i = ft_write(d % 10 + '0', i);
	}
	return (i);
}

int	ft_formats(const char *format, va_list args, int i, int j)
{
	if (format[j] == 'c')
		i += ft_printchar(va_arg(args, int));
	if (format[j] == 's')
		i = ft_printstr(va_arg(args, char *), i);
	if (format[j] == 'p')
		i = ft_printptr(args, i);
	if (format[j] == 'd')
		i = ft_printdecimal(va_arg(args, size_t), i);
	if (format[j] == 'i')
		i = ft_printdecimal(va_arg(args, int), i);
	if (format[j] == 'u')
		i = ft_uint(va_arg(args, unsigned int), i);
	if (format[j] == 'x')
		i = ft_hex(va_arg(args, size_t), 'x', i);
	if (format[j] == 'X')
		i = ft_hex(va_arg(args, size_t), 'X', i);
	if (format[j] == '%')
		i += ft_printperc();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
			i = ft_formats(format, args, i, ++j);
		else
		{
			i++;
			write(1, &format[j], 1);
		}
		j++;
	}
	va_end(args);
	return (i);
}

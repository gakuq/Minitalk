/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 01:05:15 by mmaterna          #+#    #+#             */
/*   Updated: 2025/01/30 09:29:42 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long num)
{
	int		count;
	char	*hex_digits;

	count = 0;
	hex_digits = "0123456789abcdef";
	if (num / 16)
		count += ft_puthex(num / 16);
	count += ft_putchar(hex_digits[num % 16]);
	return (count);
}

int	ft_hex(size_t x, char spec, int i)
{
	unsigned int	u;

	u = (unsigned int)x;
	if (u == 0)
		i = ft_write('0', i);
	else if (u >= 16)
	{
		i = ft_hex(u / 16, spec, i);
		i = ft_hex(u % 16, spec, i);
	}
	else
	{
		if (u <= 9)
			i = ft_write(u + '0', i);
		else if (spec == 'x')
			i = ft_write(u + 'a' - 10, i);
		else
			i = ft_write(u + 'A' - 10, i);
	}
	return (i);
}

int	ft_printptr(va_list args, int i)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (!ptr)
	{
		i += ft_putstr("(nil)");
	}
	else
	{
		i += ft_putstr("0x");
		i += ft_puthex((unsigned long)ptr);
	}
	return (i);
}

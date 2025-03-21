/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:21:06 by mmaterna          #+#    #+#             */
/*   Updated: 2025/01/30 09:30:00 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write(int c, int i)
{
	i++;
	write(1, &c, 1);
	return (i);
}

int	ft_uint(unsigned int u, int i)
{
	if (u / 10)
		i = ft_uint(u / 10, i);
	i = ft_write((u % 10) + '0', i);
	return (i);
}

int	ft_printperc(void)
{
	ft_write('%', 1);
	return (1);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

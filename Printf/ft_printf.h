/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 22:08:21 by mmaterna          #+#    #+#             */
/*   Updated: 2025/01/30 09:30:45 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>

int		ft_printptr(va_list args, int i);
int		ft_printf(const char *format, ...);
int		ft_hex(size_t x, char spec, int i);
int		ft_uint(unsigned int u, int i);
int		ft_printperc(void);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_write(int c, int i);
char	*ft_convert_hex(unsigned long num, char spec);

#endif

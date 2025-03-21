/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:26:59 by mmaterna          #+#    #+#             */
/*   Updated: 2024/12/18 22:38:29 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	num_len;

	num_len = 0;
	if (n <= 0)
	{
		num_len++;
		n = -n;
	}
	while (n)
	{
		n /= 10;
		num_len++;
	}
	return (num_len);
}

void	int_to_str(char *s, int len, long n)
{
	while (n > 0)
	{
		s[len--] = (n % 10) + '0';
		n /= 10;
	}
	if (len == 0 && s[len] != '-')
		s[len] = '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num_len;
	long	num;

	num = n;
	num_len = ft_numlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_calloc(num_len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	int_to_str(str, num_len - 1, num);
	return (str);
}

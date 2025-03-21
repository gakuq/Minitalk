/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:18:43 by mmaterna          #+#    #+#             */
/*   Updated: 2024/12/12 19:18:44 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char *)s1;
	j = (unsigned char *)s2;
	while (n--)
	{
		if (*i != *j)
			return (*i - *j);
		i++;
		j++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 19:04:50 by mmaterna          #+#    #+#             */
/*   Updated: 2024/12/12 19:04:53 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*i;
	unsigned char	j;

	i = (unsigned char *) s;
	j = (unsigned char) c;
	while (n--)
	{
		if (*i == j)
			return (i);
		i++;
	}
	return (NULL);
}
